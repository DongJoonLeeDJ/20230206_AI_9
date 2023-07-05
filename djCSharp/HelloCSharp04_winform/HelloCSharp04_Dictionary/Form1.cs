using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HelloCSharp04_Dictionary
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        Dictionary<string, string> memo = new Dictionary<string, string>();

        private void button1_Click(object sender, EventArgs e)
        {
            if(memo.ContainsKey(textBox1.Text))
            {
                MessageBox.Show("그 키는 이미 있습니다.");
                return;
            }
            memo[textBox1.Text] = textBox2.Text;

            string title = "";
            foreach(string key in memo.Keys)
            {
                title += "키:"+key+",값:" + memo[key]+"\n";
            }
            label1.Text = title;
        }

        //1초에 한 번(내가 지정한 시간)
        //실행하는 것
        private void timer1_Tick(object sender, EventArgs e)
        {
            string mytime
                = DateTime.Now.ToString("yyyy년MM월dd일 HH시mm분ss초");
            label2.Text = mytime;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            timer1.Enabled = false;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            timer1.Enabled = true;
        }
    }
}
