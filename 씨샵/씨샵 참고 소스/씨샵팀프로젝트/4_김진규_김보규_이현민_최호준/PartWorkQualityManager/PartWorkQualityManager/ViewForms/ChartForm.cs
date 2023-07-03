using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.ProgressBar;
using System.Windows.Forms.DataVisualization.Charting;

namespace PartWorkQualityManager.Forms
{
    public partial class ChartForm : Form
    {
        DataManager dataManager = null;
        int count = 0; //날짜별로 ng만 있거나 good만 있는 경우 체크용 변수
        List<string> parts = new List<string>();
        public ChartForm()
        {
            InitializeComponent();
            dataManager = DBManager.Instance;
            show_date_list();
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

            chart_display.ChartAreas[0].AxisY.LineColor = System.Drawing.Color.Gray;
            chart_display.ChartAreas[0].AxisX.MajorGrid.LineColor = System.Drawing.Color.Silver;
            chart_display.ChartAreas[0].AxisY.MajorGrid.LineColor = System.Drawing.Color.Silver;
            chart_display.ChartAreas[0].AxisX.Enabled = AxisEnabled.True;

            chart_display.Series[0].ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Column;
            chart_display.Series[1].ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Column;

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

        private bool checkDate()
        {
            return comboBox_dateList.Text.Trim().Length == 0 ? false : true;
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

            var groupbyCategoryQualityResultSelected = (from q in dataManager.qualityManagers.Where(x => x.date_created.ToString("yyyy-MM-dd") == comboBox_dateList.Text)
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
        private void button_all_quality_Click(object sender, EventArgs e)
        {
            show_all_data_pie();
        }
    }
}
