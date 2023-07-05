using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HelloCSharp04_03_ref_out
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }


        void swap(ref int a, ref int b)
        {
            MessageBox.Show("a="+a);
            MessageBox.Show("b="+b);
            int temp = a;
            a = b;
            b = temp;
            MessageBox.Show("a=" + a);
            MessageBox.Show("b=" + b);
        }
        void swap(int a, int b)
        {
            int temp = a;
            a = b;
            b = temp;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int a = int.Parse(textBox1.Text);
            int b = int.Parse(textBox2.Text);
            label1.Text = $"a={a}, b={b}";
            swap( a, b);
            label2.Text = $"a={a}, b={b}";

        }

        private void increase(int num, out int a)
        {
            a = num;//out은 ref랑 같은 기능
            a++;    //ref는 읽기만 할 수도 있고
                    //대입을 할 수도 있다.
                    //out은 반 드 시 대입을 해서
                    //값을 바꿔야 됨
                    //이걸 잘 활용하면 2개 이상의 값을
                    //리턴하는 것처럼 보이게 할 수 있다.
        }
        private void button2_Click(object sender, EventArgs e)
        {
            int num = int.Parse(textBox3.Text);
            increase(num, out int a);
            bool result = int.TryParse(textBox3.Text, out num);
            label3.Text = a.ToString();
        }
    }
}
