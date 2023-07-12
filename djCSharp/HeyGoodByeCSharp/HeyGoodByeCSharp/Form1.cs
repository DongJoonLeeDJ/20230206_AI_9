using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HeyGoodByeCSharp
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            chart1.Series[0].Name = "C# 실력";
            chart1.Series[0].Points.AddXY(1, 2);
            chart1.Series[0].Points.AddXY(2, 1);
            chart1.Series[0].Points.AddXY(3, 5);

            chart2.Series[0].Points.AddXY(0.0, 10);
            chart2.Series[0].Points.Add(new double[] {2.0});
            chart2.Series[0].Name = "level";
            chart2.Series.Add("data");
            chart2.Series[0].Points.Add(new double[] { 5.0 });
            chart2.Series[1].Points.Add(new double[] { 20.0 });
            chart2.Series[1].Points.Add(new double[] { 50.0 });

            chart3.ChartAreas[0].AxisX.LabelStyle.Interval = 1;
            for (int i = 0; i < 10; i++)
                chart3.Series["Series1"].Points.AddXY(i, i + 10);
        }
    }
}
