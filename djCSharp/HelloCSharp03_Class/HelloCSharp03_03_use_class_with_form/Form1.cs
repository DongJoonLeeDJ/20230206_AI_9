using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HelloCSharp03_03_use_class_with_form
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Random r = new Random();
            label_random.Text = r.Next(1, 101).ToString();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Student s = new Student();
            s.name = textBox1.Text;
            s.age = int.Parse(textBox2.Text);
            label2.Text = $"학생의 이름 {s.name}, 나이 {s.age}살";
        }
    }
}
