using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HelloCSharp05_04_Inheri_winform
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //모달 방식
            //뒤에꺼 안 눌림
            int a = 10;
            MessageBox.Show("Test");//여기서 코드 멈춤
            a++;
            MessageBox.Show("a="+a);

        }

        private void button2_Click(object sender, EventArgs e)
        {
            //모달리스 방식(Modeless)
            //뒤에꺼 눌리고 코드도 계속 진행됨
            int a = 10;
            Form2 f = new Form2();
            f.Show();
            a++;
            MessageBox.Show("a는"+a);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            //모달리스 방식
            new Form2().ShowDialog();
        }

        private void circularButton1_Click(object sender, EventArgs e)
        {
            new Form2(textBox1.Text).Show();
        }
    }
}
