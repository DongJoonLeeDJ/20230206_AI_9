using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace HelloCSharp06_07_LINQ
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //Linq = Language-Integrated Query
            //SQL 문법을 본따서 만든 것
            List<int> input = new List<int>()
            { 1,2,3,4,5,6,7,8,9,10};
            var output = from item in input where item % 2 == 0 select item;
            foreach(var item in output ) 
            {
                Console.WriteLine(item);
            }
            var powers = from item in input select item * item;
            foreach (var item in powers)
            {
                Console.WriteLine(item);
            }

            string url = "http://www.kma.go.kr/wid/queryDFSRSS.jsp?zone=11500611500";
            //XML 형태의 문서를 불러오는 기능 사용함
            XElement xe = XElement.Load(url);
            Console.WriteLine(xe);
            //xQ : XML 문서의 내용중에 <data>태그에 있는 것들만 긁어온 것
            var xQ = from item in xe.Descendants("data") select item;
            foreach(var item in xQ)
                Console.WriteLine(item);
            foreach(var item in xQ)
                Console.WriteLine(item.Element("wdKor"));
            var myXQ = from item in xe.Descendants("data")
                       select
                       new
                       {
                           Day = item.Element("day").Value,
                           WdKor = item.Element("wdKor").Value,
                           WfKor = item.Element("wfKor").Value
                       };
            foreach(var item in myXQ)
                Console.WriteLine(item.Day+","+item.WdKor+","+item.WfKor);


        }
    }
}
