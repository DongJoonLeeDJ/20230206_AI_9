using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HelloCSharp06_03_labelLink_check
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            System.Diagnostics.Process.Start
                ("https://www.naver.com");
        }

        private void button1_Click(object sender, EventArgs e)
        {
            List<string>list= new List<string>();
            foreach(var item in Controls)
            {
                if(item is CheckBox)
                {
                    CheckBox temp = item as CheckBox;
                    if(temp.Checked)
                        list.Add(temp.Text);
                }
            }
            MessageBox.Show(string.Join(",",list));
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string select = "";
            foreach(var item in Controls)
            {
                if(item is RadioButton)
                {
                    RadioButton temp = item as RadioButton;
                    if (temp.Checked)
                        select = temp.Text;
                }
            }
            MessageBox.Show("선택:"+select);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            foreach(var item in Controls)
            {
                if(item is GroupBox
                    && (item as GroupBox).Text.Equals("groupBox1"))
                {
                    foreach(var innerItem in (item as GroupBox).Controls)
                    {
                        RadioButton r = innerItem as RadioButton;
                        string select = "";
                        if (r != null && r.Checked) //형 변환을 성공한 경우
                        {
                            select = r.Text;
                            MessageBox.Show(select);
                        }
                    }
                }
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            foreach(var item in groupBox2.Controls)
            {
                if(item is RadioButton) 
                {
                    RadioButton r = item as RadioButton;
                    if(r.Checked)
                        MessageBox.Show(r.Text);
                }
            }
        }
    }
}
