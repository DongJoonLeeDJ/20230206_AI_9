using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml.Linq;

namespace HelloCSharp06_08_XML_DataGridView_API
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            string url = "http://www.kma.go.kr/wid/queryDFSRSS.jsp?zone=11500611500";
            XElement xe = XElement.Load(url);
            List<Weather> weathers = new List<Weather>();
            weathers = (from item in xe.Descendants("data") 
                        select new Weather()
            {
                Temp = item.Element("temp").Value,
                WfKor = item.Element("wfKor").Value
            }).ToList<Weather>();
            dataGridView1.DataSource = null;
            dataGridView1.DataSource = weathers;
        }
    }
}
