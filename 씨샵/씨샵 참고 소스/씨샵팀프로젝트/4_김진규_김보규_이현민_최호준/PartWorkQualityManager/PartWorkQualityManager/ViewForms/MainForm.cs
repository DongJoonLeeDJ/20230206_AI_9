using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Reflection.Emit;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.DataVisualization.Charting;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.Button;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;
using System.Collections;
using PartWorkQualityManager.Forms;
using System.IO;

namespace PartWorkQualityManager
{
    public partial class MainForm : Form
    {
        DataManager dataManager = null;
        List<string> parts = new List<string>();
        int count = 0; //날짜별로 ng만 있거나 good만 있는 경우 체크용 변수

        public MainForm()
        {
            InitializeComponent();
            initUI();
        }

        public void initUI()
        {
            chart_display.Visible = false;
            chart_display.Series.Clear();
            show_grid_view();
            show_all_data_pie();
            show_date_list();
            show_categories();
        }

        private void show_categories()
        {
            comboBox_categories.DataSource = null;
            comboBox_categories.DataSource = dataManager.categories;
            comboBox_categories.DisplayMember = TableNames.NAME;
            comboBox_categories.ValueMember = TableNames.ID;
        }

        private void show_date_list()
        {
            List<QualityManager> dayList = (from item in dataManager.qualityManagers
                                            orderby item.date_created
                                            group item by item.date_created into g
                                            select new QualityManager()
                                            {
                                                date_created = g.Key
                                            }).ToList<QualityManager>();

            comboBox_dateList.DataSource = null;
            comboBox_dateList.DataSource = dayList;
            comboBox_dateList.DisplayMember = TableNames.DATE_CREATED;
            comboBox_dateList.ValueMember = TableNames.DATE_CREATED;
        }
        private void show_grid_view()
        {
            dataManager = DBManager.Instance;//처음 읽을 떈 시간이 걸린다.
            dataManager.setDataGridView(dataGridView_QualityManager, dataManager.qualityManagers);
            dataManager.setDataGridView(dataGridView_FileImage, dataManager.fileImages);
        }
        private void show_all_data_pie()
        {

            chart_display.Series.Clear();

            chart_display.Visible = true;

            int count_good, count_ng;
            count_good = dataManager.qualityManagers.Count(x => x.attribute_quality);
            count_ng = dataManager.qualityManagers.Count(x => !x.attribute_quality);
            chart_display.Series.Add(new Series());

            chart_display.Series[0].ChartType = SeriesChartType.Pie;
            chart_display.Series[0].Points.Clear();
            chart_display.Series[0].Points.AddXY("양품", count_good);
            chart_display.Series[0].Points.AddXY("불량품", count_ng);
            double sum = count_good + count_ng;
            chart_display.Series[0].Points[0].Label = "양품 : " + count_good + $"({Math.Round((count_good / sum) * 100, 2)}%)";
            chart_display.Series[0].Points[1].Label = "불량품 : " + count_ng + $"({Math.Round((count_ng / sum) * 100, 2)}%)";
            chart_display.Series[0].Points[0].Color = Color.Lime;
            chart_display.Series[0].Points[1].Color = Color.Red;
        }

        private void dataGridView_QualityManager_CellDoubleClick(object sender, DataGridViewCellEventArgs e)
        {
            //수정,삭제용
            new QualityDataForm((sender as DataGridView).CurrentRow.DataBoundItem as QualityManager).ShowDialog();
            dataManager.setDataGridView(dataGridView_QualityManager, dataManager.qualityManagers);
            dataManager.setDataGridView(dataGridView_FileImage, dataManager.fileImages);
        }

        private void dataGridView_FileImage_CellDoubleClick(object sender, DataGridViewCellEventArgs e)
        {
            //데이터 추가용
            new QualityDataForm((sender as DataGridView).CurrentRow.DataBoundItem as FileImage).ShowDialog();
            dataManager.setDataGridView(dataGridView_QualityManager, dataManager.qualityManagers);
            dataManager.setDataGridView(dataGridView_FileImage, dataManager.fileImages);
        }

        private void dataGridView_QualityManager_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            QualityManager qm = (sender as DataGridView).CurrentRow.DataBoundItem as QualityManager;
            textBox_file_name.Text = qm.file_name;
            comboBox_categories.SelectedValue = qm.category_id;
        }

        private void dataGridView_FileImage_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            //
        }

        private void button_name_search_Click(object sender, EventArgs e)
        {
            dataManager.setDataGridView(dataGridView_QualityManager, dataManager.qualityManagers.Where(x => x.file_name.Contains(textBox_file_name.Text)).ToList());
            dataManager.setDataGridView(dataGridView_FileImage, dataManager.fileImages.Where(x => x.file_name.Contains(textBox_file_name.Text)).ToList());
        }

        private void button_init_Click(object sender, EventArgs e)
        {
        }

        private void 초기화ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            DialogResult d = MessageBox.Show("초기화 하시겠습니까?");
            if (d == DialogResult.OK)
            {
                initUI();
            }
        }

        private void chart_init()
        {
            chart_display.Visible = true;
            chart_display.Series.Clear();
            chart_display.Series.Add("양품");
            chart_display.Series.Last().Color = Color.Lime;
            chart_display.Series.Add("불량품");
            chart_display.Series.Last().Color = Color.Red;
            count = 0;
            parts.Clear();

            chart_display.ChartAreas[0].AxisY.LineColor = Color.Gray;
            chart_display.ChartAreas[0].AxisX.MajorGrid.LineColor = Color.Silver;
            chart_display.ChartAreas[0].AxisY.MajorGrid.LineColor = Color.Silver;
            chart_display.ChartAreas[0].AxisX.Enabled = AxisEnabled.True;

            chart_display.Series[0].ChartType = SeriesChartType.Column;
            chart_display.Series[1].ChartType = SeriesChartType.Column;

        }

        private void button_chart_by_category_Click(object sender, EventArgs e)
        {
            var groupbyCategoryQualityResult = (from q in dataManager.qualityManagers
                                                group q by new
                                                {
                                                    q.category_id,
                                                    q.attribute_quality
                                                } into groupData
                                                select new
                                                {
                                                    CategoryName = dataManager.categories.Single(x => x.id == groupData.Key.category_id).name,
                                                    Quality = groupData.Key.attribute_quality,
                                                    Count = groupData.Count()
                                                });
            chart_init();
            foreach (var part in groupbyCategoryQualityResult)
            {
                parts.Remove(part.CategoryName);
                parts.Add(part.CategoryName);
            }

            foreach (var group in groupbyCategoryQualityResult)
            {
                string result = group.Quality ? "양품" : "불량품";

                if (group.Quality)
                {
                    chart_display.Series[0].Points.AddXY(parts[count / 2], group.Count);
                    chart_display.Series[0].Points.Last().Label = group.Count + "";
                }
                else
                {
                    chart_display.Series[1].Points.AddXY(parts[count / 2], group.Count);
                    chart_display.Series[1].Points.Last().Label = group.Count + "";
                }
                count++;
            }

        }
    

        private void button_chart_by_part_Click(object sender, EventArgs e)
        {
            var groupbyPartQualityResult = (from q in dataManager.qualityManagers
                                            group q by new
                                            {
                                                q.attribute_part,
                                                q.attribute_quality
                                            } into groupData
                                            select new
                                            {
                                                PartName = groupData.Key.attribute_part,
                                                Quality = groupData.Key.attribute_quality,
                                                Count = groupData.Count()
                                            });
            chart_init();

            foreach (var part in groupbyPartQualityResult)
            {
                parts.Remove(part.PartName);
                parts.Add(part.PartName);
            }
            foreach (var group in groupbyPartQualityResult)
            {
                string result = group.Quality ? "양품" : "불량품";

                if (group.Quality)
                {
                    chart_display.Series[0].Points.AddXY(parts[count / 2], group.Count);
                    chart_display.Series[0].Points.Last().Label = group.Count + "";
                }
                else
                {
                    chart_display.Series[1].Points.AddXY(parts[count / 2], group.Count);
                    chart_display.Series[1].Points.Last().Label = group.Count + "";

                }
                count++;


            }

        }

        private void button_chart_by_work_Click(object sender, EventArgs e)
        {

            var groupbyWorkQualityResult = (from q in dataManager.qualityManagers
                                            group q by new
                                            {
                                                q.attribute_work,
                                                q.attribute_quality
                                            } into groupData
                                            select new
                                            {
                                                Work = groupData.Key.attribute_work,
                                                Quality = groupData.Key.attribute_quality,
                                                Count = groupData.Count()
                                            });
            chart_init();

            foreach (var part in groupbyWorkQualityResult)
            {
                parts.Remove(part.Work);
                parts.Add(part.Work);
            }
            foreach (var group in groupbyWorkQualityResult)
            {
                string result = group.Quality ? "양품" : "불량품";

                if (group.Quality)
                {
                    chart_display.Series[0].Points.AddXY(parts[count / 2], group.Count);
                    chart_display.Series[0].Points.Last().Label = group.Count + "";
                }
                else
                {
                    chart_display.Series[1].Points.AddXY(parts[count / 2], group.Count);
                    chart_display.Series[1].Points.Last().Label = group.Count + "";
                }
                count++;


            }

        }
        private void button_chart_by_allDays_Click(object sender, EventArgs e)
        {
            var groupbyDateCreatedQualityResult = (from q in dataManager.qualityManagers
                                                   orderby q.date_created, q.attribute_quality descending
                                                   group q by new
                                                   {
                                                       q.date_created,
                                                       q.attribute_quality
                                                   } into groupData
                                                   select new
                                                   {
                                                       DateCreated = groupData.Key.date_created,
                                                       Quality = groupData.Key.attribute_quality,
                                                       Count = groupData.Count()
                                                   });
            chart_init();

            chart_display.Series[0].ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            chart_display.Series[1].ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            chart_display.ChartAreas[0].AxisX.Enabled = AxisEnabled.False;

            for (int i = 0; i < groupbyDateCreatedQualityResult.Count();)
            {
                var group = groupbyDateCreatedQualityResult.ElementAt(i);

                string nowDate = group.DateCreated.ToString("yyyy년 MM월 dd일");
                string nextDate = null;
                int nextCount = -1;
                try
                {
                    //i가 맨 마지막 인덱스인 경우
                    nextDate = groupbyDateCreatedQualityResult.ElementAt(i + 1).DateCreated.ToString("yyyy년 MM월 dd일");
                    nextCount = groupbyDateCreatedQualityResult.ElementAt(i + 1).Count;
                }
                catch (Exception ex)
                {
                }

                if (nowDate == nextDate)
                {
                    //양불 둘 다 추가해주고 i는 2씩 증가
                    chart_display.Series[0].Points.AddY(group.Count);
                    chart_display.Series[1].Points.AddY(nextCount);

                    i += 2;
                }
                else
                {
                    //현재랑 다음 날짜가 다르거나 다음 날짜가 없는 경우
                    if (group.Quality) //현재꺼가 양품인 데, 양품만 있는 경우
                    {
                        chart_display.Series[0].Points.AddY(group.Count);
                        chart_display.Series[1].Points.AddY(0);
                    }
                    else//현재꺼가 불량품인 데, 양품만 있는 경우
                    {
                        chart_display.Series[0].Points.AddY(0);
                        chart_display.Series[1].Points.AddY(group.Count);
                    }
                    i++;
                }

            }
        }

        private void button_chart_by_selected_category_Click(object sender, EventArgs e)
        {

            if (!checkDate())
            {
                MessageBox.Show("날짜를 선택하세요.");
                return;
            }

            var groupbyCategoryQualityResultSelected = (from q in dataManager.qualityManagers.
                                                        Where(x => x.date_created.ToString("yyyy-MM-dd") == comboBox_dateList.Text)
                                                        group q by new
                                                        {
                                                            q.category_id,
                                                            q.attribute_quality
                                                        } into groupData
                                                        select new
                                                        {
                                                            CategoryName = dataManager.categories.
                                                            Single(x => x.id == groupData.Key.category_id).name,
                                                            Quality = groupData.Key.attribute_quality,
                                                            Count = groupData.Count()
                                                        });




            chart_init();

            foreach (var part in groupbyCategoryQualityResultSelected)
            {
                parts.Remove(part.CategoryName);
                parts.Add(part.CategoryName);

            }
            //축의 수가 일정치 않아 미리 만든다(날짜별로 오류가 발생하지 않은 유형도 있어서 수가 들쭉 날쭉)
            foreach (var part in parts)
            {
                chart_display.Series[0].Points.AddXY(part, 0);
                chart_display.Series[1].Points.AddXY(part, 0);
            }


            for (int i = 0; i < groupbyCategoryQualityResultSelected.Count(); i++)
            {
                var group = groupbyCategoryQualityResultSelected.ElementAt(i);
                string result = group.Quality ? "양품" : "불량품";


                for (int j = 0; j < chart_display.Series[0].Points.Count; j++)
                {
                    if (chart_display.Series[0].Points[j].AxisLabel == group.CategoryName)
                    {
                        if (group.Quality)
                        {

                            double y = chart_display.Series[0].Points[j].GetValueByName("Y");
                            y += group.Count;
                            chart_display.Series[0].Points[j].SetValueY(y);
                            chart_display.Series[0].Points[j].Label = y + "";
                        }
                        else
                        {

                            double y = chart_display.Series[1].Points[j].GetValueByName("Y");
                            y += group.Count;
                            chart_display.Series[1].Points[j].SetValueY(y);
                            chart_display.Series[1].Points[j].Label = y + "";
                        }

                    }
                }
            }
        }

        private bool checkDate()
        {
            return comboBox_dateList.Text.Trim().Length == 0 ? false : true;
        }

        private void button_chart_by_selected_part_Click(object sender, EventArgs e)
        {
            if (!checkDate())
            {
                MessageBox.Show("날짜를 선택하세요.");
                return;
            }

            var groupbyPartQualityResultSelectDay = (from q in dataManager.qualityManagers.Where(x => x.date_created.ToString("yyyy-MM-dd") == comboBox_dateList.Text)
                                                     group q by new
                                                     {
                                                         q.attribute_part,
                                                         q.attribute_quality
                                                     } into groupData
                                                     select new
                                                     {
                                                         PartName = groupData.Key.attribute_part,
                                                         Quality = groupData.Key.attribute_quality,
                                                         Count = groupData.Count()
                                                     });

            chart_init();
            foreach (var part in groupbyPartQualityResultSelectDay)
            {
                parts.Remove(part.PartName);
                parts.Add(part.PartName);

            }
            foreach (var part in parts)
            {
                chart_display.Series[0].Points.AddXY(part, 0);
                chart_display.Series[1].Points.AddXY(part, 0);
            }

            for (int i = 0; i < groupbyPartQualityResultSelectDay.Count(); i++)
            {
                var group = groupbyPartQualityResultSelectDay.ElementAt(i);
                string result = group.Quality ? "양품" : "불량품";


                for (int j = 0; j < chart_display.Series[0].Points.Count; j++)
                {
                    if (chart_display.Series[0].Points[j].AxisLabel == group.PartName)
                    {
                        if (group.Quality)
                        {

                            double y = chart_display.Series[0].Points[j].GetValueByName("Y");
                            y += group.Count;
                            chart_display.Series[0].Points[j].SetValueY(y);
                            chart_display.Series[0].Points[j].Label = y + "";
                        }
                        else
                        {

                            double y = chart_display.Series[1].Points[j].GetValueByName("Y");
                            y += group.Count;
                            chart_display.Series[1].Points[j].SetValueY(y);
                            chart_display.Series[1].Points[j].Label = y + "";
                        }

                    }
                }


            }
        }

        private void button_chart_by_selected_work_Click(object sender, EventArgs e)
        {

            if (!checkDate())
            {
                MessageBox.Show("날짜를 선택하세요.");
                return;
            }

            var groupbyWorkQualityResultSelectDay = (from q in dataManager.qualityManagers.Where(x => x.date_created.ToString("yyyy-MM-dd") == comboBox_dateList.Text)
                                                     group q by new
                                                     {
                                                         q.attribute_work,
                                                         q.attribute_quality
                                                     } into groupData
                                                     select new
                                                     {
                                                         Work = groupData.Key.attribute_work,
                                                         Quality = groupData.Key.attribute_quality,
                                                         Count = groupData.Count()
                                                     });

            chart_init();
            foreach (var part in groupbyWorkQualityResultSelectDay)
            {
                parts.Remove(part.Work);
                parts.Add(part.Work);
            }
            foreach (var part in parts)
            {
                chart_display.Series[0].Points.AddXY(part, 0);
                chart_display.Series[1].Points.AddXY(part, 0);
            }

            foreach (var group in groupbyWorkQualityResultSelectDay)
            {
                string result = group.Quality ? "양품" : "불량품";


                for (int j = 0; j < chart_display.Series[0].Points.Count; j++)
                {
                    if (chart_display.Series[0].Points[j].AxisLabel == group.Work)
                    {
                        if (group.Quality)
                        {

                            double y = chart_display.Series[0].Points[j].GetValueByName("Y");
                            y += group.Count;
                            chart_display.Series[0].Points[j].SetValueY(y);
                            chart_display.Series[0].Points[j].Label = y + "";
                        }
                        else
                        {

                            double y = chart_display.Series[1].Points[j].GetValueByName("Y");
                            y += group.Count;
                            chart_display.Series[1].Points[j].SetValueY(y);
                            chart_display.Series[1].Points[j].Label = y + "";
                        }

                    }
                }
                count++;


            }

        }

        private void button_chart_by_selected_days_Click(object sender, EventArgs e)
        {
            if (!checkDate())
            {
                MessageBox.Show("날짜를 선택하세요.");
                return;
            }


            var groupbyDateCreatedQualityResult = (from q in dataManager.qualityManagers
                                                   where q.date_created >= (comboBox_dateList.SelectedItem as QualityManager).date_created
                                                   orderby q.date_created, q.attribute_quality descending
                                                   group q by new
                                                   {
                                                       q.date_created,
                                                       q.attribute_quality
                                                   } into groupData
                                                   select new
                                                   {
                                                       DateCreated = groupData.Key.date_created,
                                                       Quality = groupData.Key.attribute_quality,
                                                       Count = groupData.Count()
                                                   });
            chart_init();
            foreach (var part in groupbyDateCreatedQualityResult)
            {
                //parts.Remove(part.DateCreated.ToString("yyyy년 MM월 dd일")); //중복삭제 하지 않고 그대로 넣음
                parts.Add(part.DateCreated.ToString("yyyy년 MM월 dd일"));
            }
            for (int i = 0, c = 0; i < groupbyDateCreatedQualityResult.Count();)
            {
                var group = groupbyDateCreatedQualityResult.ElementAt(i);

                string nowDate = group.DateCreated.ToString("yyyy년 MM월 dd일");
                string nextDate = null;
                int nextCount = -1;
                try
                {
                    //i가 맨 마지막 인덱스인 경우
                    nextDate = groupbyDateCreatedQualityResult.ElementAt(i + 1).DateCreated.ToString("yyyy년 MM월 dd일");
                    nextCount = groupbyDateCreatedQualityResult.ElementAt(i + 1).Count;
                }
                catch (Exception ex)
                {
                }

                if (nowDate == nextDate)
                {
                    //양불 둘 다 추가해주고 i는 2씩 증가
                    chart_display.Series[0].Points.AddXY(nowDate, group.Count);
                    chart_display.Series[0].Points.Last().Label = group.Count + "";
                    chart_display.Series[1].Points.AddXY(nowDate, nextCount);
                    chart_display.Series[1].Points.Last().Label = nextCount + "";

                    i += 2;
                }
                else
                {
                    //현재랑 다음 날짜가 다르거나 다음 날짜가 없는 경우
                    if (group.Quality) //현재꺼가 양품인 데, 양품만 있는 경우
                    {
                        chart_display.Series[0].Points.AddXY(nowDate, group.Count);
                        chart_display.Series[0].Points.Last().Label = group.Count + "";
                        chart_display.Series[1].Points.AddXY(nowDate, 0);
                        chart_display.Series[1].Points.Last().Label = "";
                    }
                    else//현재꺼가 불량품인 데, 양품만 있는 경우
                    {
                        chart_display.Series[0].Points.AddXY(nowDate, 0);
                        chart_display.Series[0].Points.Last().Label = "";
                        chart_display.Series[1].Points.AddXY(nowDate, group.Count);
                        chart_display.Series[1].Points.Last().Label = group.Count + "";
                    }
                    i++;
                }
                c++;
                if (c >= 10)
                    break;

            }
        }

        private void 차트출력ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            new ChartForm().Show(); //모달리스로 출력
        }

        private void 항목관리ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            new TableColumnsManagerForm().ShowDialog();
        }

        private void 개별등록ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            new QualityDataForm().ShowDialog();
            dataManager.setDataGridView(dataGridView_QualityManager, dataManager.qualityManagers);
            dataManager.setDataGridView(dataGridView_FileImage, dataManager.fileImages);
        }

        private void 일괄등록ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if(DialogResult.OK== MessageBox.Show("폴더를 이용하여 일괄 등록하시겠습니까? 시간이 오래 소요될 수 있습니다."))
            {

                try
                {
                    DialogResult d = folderBrowserDialog_QualityData.ShowDialog();
                    string readPath = ""; ;
                    if (d == DialogResult.OK)
                    {
                        readPath = folderBrowserDialog_QualityData.SelectedPath;
                        string[] allfiles = Directory.GetFiles(readPath, "*.*", SearchOption.AllDirectories);
                        foreach (string file in allfiles)
                        {
                            Dictionary<string, object> fileData = new Dictionary<string, object>();
                            fileData["extension"] = Path.GetExtension(file).ToLower();
                            fileData["fileName"] = Path.GetFileName(file);
                            fileData["directory"] = Path.GetDirectoryName(file);
                            fileData["file"] = file;
                            dataManager.Add(fileData);
                        }
                    }
                }
                catch (Exception ex)
                {
                    dataManager.printLog("일괄 등록 실패");
                    dataManager.printLog(ex.Message);
                    dataManager.printLog(ex.StackTrace);
                    MessageBox.Show("일괄 등록 실패 " + ex.Message);
                }
            }
        }
    }
}
