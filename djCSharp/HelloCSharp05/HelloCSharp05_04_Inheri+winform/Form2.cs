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
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();//반드시 같이 가져오기!!!
        }
        //생성자 오버로딩
        public Form2(string text)
        {
            InitializeComponent();
            textBox1.Text = text;
        }
    }
}
