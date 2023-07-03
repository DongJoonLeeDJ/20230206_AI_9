using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PartWorkQualityManager.Forms
{
    public partial class QualityDataForm : Form
    {

        DataManager dataManager = DBManager.Instance;
        FileImage f = null;
        QualityManager q = null;
        Dictionary<string, object> data = new Dictionary<string, object>();
        //개별 등록
        //json을 읽어오고 jpg 파일 읽어 오거나
        //jpg 파일 읽고 나머진 수동으로 쓴 다음 입력
        //이 떈 입력 버튼만 활성화된다.

        void setDataSource()
        {


            comboBox_category_id.DataSource = dataManager.categories;
            comboBox_category_id.DisplayMember = TableNames.NAME;
            comboBox_category_id.ValueMember = TableNames.ID;

            comboBox_part.DataSource = dataManager.partLists;
            comboBox_part.DisplayMember = TableNames.CARPART;
            comboBox_part.ValueMember = TableNames.CARPART;

            comboBox_work.DataSource = dataManager.partWorkLists;
            comboBox_work.DisplayMember = TableNames.WORKNAME;
            comboBox_work.ValueMember = TableNames.WORKNAME;
        }
        public QualityDataForm()
        {
            InitializeComponent();
            checkBox_only_fileImage.Checked = true;
            button_insert_Quality.Enabled = true;
            button_update_Quality.Enabled = false;
            button_delete_Quality.Enabled = false;
            setDataSource();



        }
        //이 때는 기존 데이터를 불러온거다(이미지는 이미 있다)
        //이 떄는 양불 여부만 수정하거나 삭제만 할 수 있다.
        public QualityDataForm(QualityManager q)
        {
            InitializeComponent();
            this.q = q;
            setDataSource();
            //전부 비활성화시킴
            checkBox_only_fileImage.Checked = true;
            checkBox_only_fileImage.Enabled = false; //체크박스 해제도 못 하게 함

            button_update_Quality.Enabled = true;
            button_delete_Quality.Enabled = true;
            checkBox_quality.Enabled = true;

            textBox_file_name.Enabled = false;
            textBox_real_file_path.Enabled = false;


            button_insert_Quality.Enabled = false;
            button_read_file.Enabled = false;


            comboBox_category_id.SelectedValue = q.category_id;
            comboBox_work.SelectedValue = q.attribute_work;
            comboBox_part.SelectedValue = q.attribute_part;
            
            checkBox_quality.Checked = q.attribute_quality;


            try
            {
                f = dataManager.fileImages.Single(x => x.file_name == q.file_name);
                textBox_file_name.Text = f.file_name;
                textBox_real_file_path.Text = f.real_file_path;
                pictureBox_FileImage.Load(f.real_file_path);

            }
            catch (Exception ex)
            {
                MessageBox.Show("이미지 로드 실패");
                dataManager.printLog("이미지 로드 실패");
                dataManager.printLog(ex.Message);
                dataManager.printLog(ex.StackTrace);
            }

        }

        //기존 파일에 대한 데이터를 추가한다.
        //수정 삭제는 안 되고
        //추가만 할 수 있다.
        public QualityDataForm(FileImage f)
        {
            InitializeComponent();
            this.f = f;
            setDataSource();
            checkBox_only_fileImage.Checked = false;
            checkBox_only_fileImage.Enabled = false; //체크박스 해제도 못 하게 함

            button_insert_Quality.Enabled = true;
            button_update_Quality.Enabled = false;
            button_delete_Quality.Enabled = false;

            textBox_file_name.Enabled = false;
            textBox_real_file_path.Enabled = false;
            button_read_file.Enabled = false;

            textBox_file_name.Text = f.file_name;
            textBox_real_file_path.Text = f.real_file_path;
            try
            {
                pictureBox_FileImage.Load(f.real_file_path);

            }
            catch (Exception ex)
            {
                MessageBox.Show("이미지 로드 실패");
                dataManager.printLog("이미지 로드 실패");
                dataManager.printLog(ex.Message);
                dataManager.printLog(ex.StackTrace);
            }
        }

        private void checkBox_only_fileImage_CheckedChanged(object sender, EventArgs e)
        {
            CheckBox c = sender as CheckBox;
            if(c.Checked)
            {
                comboBox_category_id.Enabled = false;
                comboBox_part.Enabled = false;
                comboBox_work.Enabled = false;
                checkBox_quality.Enabled = false;
                button_read_json.Enabled = false;
            }
            else
            {
                comboBox_category_id.Enabled = true;
                comboBox_part.Enabled = true;
                comboBox_work.Enabled = true;
                checkBox_quality.Enabled = true;
                button_read_json.Enabled = true;
            }
        }

        private void button_insert_Quality_Click(object sender, EventArgs e)
        {

            if (textBox_file_name.Text.Trim() == "" || textBox_real_file_path.Text.Trim() == "")
            {
                MessageBox.Show("이미지 파일이 없습니다.");
                return;
            }

            //이미지가 있으면 굳이 추가할 필요 없다.
            if (dataManager.fileImages.Where(x => x.file_name == f.file_name).Count() == 0)
            {
                //이미지 추가
                data["data"] = f;
                data["tablename"] = TableNames.FILEIMAGE;
                dataManager.DataManaging((sender as Button).Name.Split('_')[1], new string[] { TableNames.FILE_NAME, TableNames.REAL_FILE_PATH, TableNames.DATETIME_CAPTURED }, data);


            }
            if (checkBox_only_fileImage.Checked) //체크된 상태라면 이미지만 등록하고 끝낸다.
                return;


            q = new QualityManager();
            q.file_name = f.file_name;
            q.category_id = comboBox_category_id.SelectedValue.ToString();
            q.datetime_created = DateTime.Now;
            q.datetime_captured = f.datetime_captured;
            q.attribute_work = comboBox_work.Text;
            q.attribute_part = comboBox_part.Text;
            q.attribute_quality = checkBox_quality.Checked;
            q.date_created = DateTime.Now;

            //데이터 추가
            data["data"] = q;
            data["tablename"] = TableNames.QUALITYMANAGER;
            dataManager.DataManaging((sender as Button).Name.Split('_')[1],
                new string[] { TableNames.FILE_NAME, TableNames.CATEGORY_ID, TableNames.DATETIME_CREATED, TableNames.DATETIME_CAPTURED,
            TableNames.ATTRIBUTE_WORK, TableNames.ATTRIBUTE_PART, TableNames.ATTRIBUTE_QUALITY, TableNames.DATE_CREATED}, data);

            try
            {

                //json export
                data = new Dictionary<string, object>();
                System.Drawing.Image img = System.Drawing.Image.FromFile(f.real_file_path);

                data["width"] = img.Width;
                data["height"] = img.Height;
                data[TableNames.QUALITYMANAGER] = q;
                data[TableNames.FILEIMAGE] = f;
                data["categories"] = dataManager.categories;
                string filename = f.file_name.ToLower();
                data["filename"] = f.file_name.Replace(".jpg", "");
                dataManager = JsonManager.Instance;
                dataManager.DataManaging("add", null, data);
            }
            catch (Exception ex)
            {
                dataManager.printLog("json export");
                dataManager.printLog(ex.Message);
                dataManager.printLog(ex.StackTrace);
            }

            MessageBox.Show((sender as Button).Name.Split('_')[1] + "작업 완료");
            Dispose();

        }


        private void button_read_json_Click(object sender, EventArgs e)
        {

            openFileDialog_Quality.Filter = "json 파일 (*.json)|*.json";
            openFileDialog_Quality.ShowDialog();

            dataManager = JsonManager.Instance;
            data = new Dictionary<string, object>();
            data["file"] = openFileDialog_Quality.FileName;
            q = new QualityManager();
            data["data"] = q;

            dataManager.DataManaging("load", null, data);

            dataManager = DBManager.Instance;

            try
            {

                f = dataManager.fileImages.Single(x => x.file_name == q.file_name);

                textBox_file_name.Text = f.file_name;
                try
                {

                    comboBox_category_id.SelectedValue = q.category_id;//값은 id, display되는 것은 name
                    comboBox_part.Text = q.attribute_part;
                    comboBox_work.Text = q.attribute_work;

                    checkBox_quality.Checked = q.attribute_quality;


                    try
                    {
                        f = dataManager.fileImages.Single(x => x.file_name == q.file_name);
                        textBox_file_name.Text = f.file_name;
                        textBox_real_file_path.Text = f.real_file_path;
                        pictureBox_FileImage.Load(f.real_file_path);

                    }
                    catch (Exception ex)
                    {
                        MessageBox.Show("이미지 로드 실패");
                        dataManager.printLog("이미지 로드 실패");
                        dataManager.printLog(ex.Message);
                        dataManager.printLog(ex.StackTrace);
                    }

                }
                catch (Exception ex)
                {
                    dataManager.printLog(ex.Message);
                    dataManager.printLog(ex.StackTrace);
                }
            }
            catch (Exception)
            {
                MessageBox.Show("해당 이미지가 없습니다. json이나 이미지 파일 혹인해주세요.");
            }



        }

        private void button_read_file_Click(object sender, EventArgs e)
        {

            openFileDialog_Quality.Filter = "이미지 파일 (*.jpg)|*.jpg";
            openFileDialog_Quality.ShowDialog();


            f = new FileImage();
            f.file_name = Path.GetFileName(openFileDialog_Quality.FileName);
            f.real_file_path = openFileDialog_Quality.FileName;
            f.datetime_captured = DateTime.Now;

            textBox_file_name.Text = f.file_name;
            textBox_real_file_path.Text = f.real_file_path;
            pictureBox_FileImage.Load(f.real_file_path);
        }

        private void ButtonClickEvent(object sender, EventArgs e)
        {
             data = new Dictionary<string, object>();

            q.attribute_quality = checkBox_quality.Checked;


            data["data"] = q;
            data["tablename"] = TableNames.QUALITYMANAGER;
            dataManager.DataManaging((sender as Button).Name.Split('_')[1],
                new string[] { TableNames.FILE_NAME, TableNames.CATEGORY_ID, TableNames.DATETIME_CREATED, TableNames.DATETIME_CAPTURED,
            TableNames.ATTRIBUTE_WORK, TableNames.ATTRIBUTE_PART, TableNames.ATTRIBUTE_QUALITY, TableNames.DATE_CREATED}, data);
            if (f != null)
            {

                data["data"] = f;
                data["tablename"] = TableNames.FILEIMAGE;
                dataManager.DataManaging((sender as Button).Name.Split('_')[1],
                new string[] { TableNames.FILE_NAME, TableNames.REAL_FILE_PATH }, data);

            }
            MessageBox.Show((sender as Button).Name.Split('_')[1] + "작업 완료");
            Dispose();
        }
        private void button_update_Quality_Click(object sender, EventArgs e)
        {
            ButtonClickEvent(sender, e);
        }

        private void button_delete_Quality_Click(object sender, EventArgs e)
        {
            ButtonClickEvent(sender, e);
        }
    }
}
