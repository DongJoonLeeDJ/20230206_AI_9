using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HelloCSharp06_05_DataGridView_getset
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            dataGridView3.DataSource = bindingSource1;
        }

        List<Animal> animals = new List<Animal>();
        private void button1_Click(object sender, EventArgs e)
        {
            Animal a = new Animal();
            a.name = textBox1.Text;
            a.alias = textBox2.Text;
            animals.Add(a);
            dataGridView2.DataSource = null;
            dataGridView2.DataSource = animals;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Animal a = new Animal();
            a.name = textBox3.Text;
            a.alias = textBox4.Text;
            bindingSource1.Add(a);
        }
    }
}
