using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HelloCSharp06_04_try_catch
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int a = int.Parse(textBox1.Text);
            label1.Text = (a*a).ToString();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                int a = int.Parse(textBox2.Text);
                label2.Text = (a * a).ToString();
            }
            catch (Exception ex)
            {
                //Environment.NewLine = "\n"
                //OS에 따라서 개행문자가 다르므로 그걸 고려한 것
                label2.Text = "정수를 입력해주세요.";
                label2.Text += Environment.NewLine+ex.Message;
                label2.Text += Environment.NewLine+ex.StackTrace;
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            try
            {
                int a= int.Parse(textBox3.Text);
                label3.Text = (a * a).ToString();
            }
            catch (Exception)
            {
                return;
            }
            finally //catch에서 무슨 코드를 실행하든 무조건 실행함
            {
                //DBMS 연결 및 해지할 때 많이 쓰임
                MessageBox.Show("버튼 클릭 완료");
            }
            MessageBox.Show("정상 처리 완료");
        }

        private void button4_Click(object sender, EventArgs e)
        {
            //내가 일부로 에러 발생시키기(throw)
            bool result = int.TryParse(textBox4.Text, out int a);

            //if(result==false)
            if (!result)
                throw new Exception("값 다시 확인해주세요.");

            label4.Text = (a * a).ToString();
        }
    }
}
