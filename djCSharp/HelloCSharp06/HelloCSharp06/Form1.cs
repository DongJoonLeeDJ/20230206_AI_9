using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HelloCSharp06
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            IsMdiContainer = true;//부모 컨테이너로 지정
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form2 f = new Form2();
            f.MdiParent = this;//Form1을 부모로 지정
            f.Show();
        }
    }
}
