using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ParkingCarManager
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            label1.Text =
            DateTime.Now.ToString
            ("yyyy년 MM월 dd일 HH시 mm분 ss초");

            try
            {
                textBox1.Text = DataManager.Cars[0].ParkingSpot;
                textBox2.Text = DataManager.Cars[0].carNumber;
                textBox3.Text = DataManager.Cars[0].driverName;
                textBox4.Text = DataManager.Cars[0].phoneNumber;
                textBox5.Text = textBox1.Text;
            }
            catch (Exception)
            {

            }
            if(DataManager.Cars.Count>0)
                dataGridView1.DataSource = DataManager.Cars;
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            label1.Text =
            DateTime.Now.ToString
            ("yyyy년 MM월 dd일 HH시 mm분 ss초");
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //WriteLog("버튼1클릭");
        }
        private void WriteLog(string contents)
        {
            string log =
                $"[{DateTime.Now.ToString("yyyy/MM/dd hh:mm:ss.fff")}]";
            log += contents;
            DataManager.printLog(log);
            listBox1.Items.Insert(0, log);//새로운 내용이 맨 위로 올라옴
            //listBox1.Items.Add(log);
            //새로운 내용이 맨 밑으로 감
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //WriteLog("버튼2클릭");
        }

        private void dataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            ParkingCar car =
                dataGridView1.CurrentRow.DataBoundItem as ParkingCar;
            textBox1.Text = car.ParkingSpot;
            textBox2.Text = car.carNumber;
            textBox3.Text = car.driverName;
            textBox4.Text = car.phoneNumber;
            textBox5.Text = textBox1.Text;

        }

        private void button3_Click(object sender, EventArgs e)
        {

        }

        private void button4_Click(object sender, EventArgs e)
        {
            spot_add_delete(textBox5.Text, "insert");
        }

        private void spot_add_delete(string text, string v)
        {
            text = text.Trim();//양옆 공백 삭제
            string contents = "";
            bool check = DataManager.Save(v, text, out contents);
            if (check)
                button6.PerformClick(); //Refresh 버튼 클릭(=전체조회)
            MessageBox.Show(contents);
            WriteLog(contents);
        }

        private void button5_Click(object sender, EventArgs e)
        {
            spot_add_delete(textBox5.Text, "delete");
        }

        private void button6_Click(object sender, EventArgs e)
        {
            DataManager.Load();//전체조회(다시불러오기)
            dataGridView1.DataSource = null;
            if(DataManager.Cars.Count>0)
                dataGridView1.DataSource=DataManager.Cars;
        }
    }
}
