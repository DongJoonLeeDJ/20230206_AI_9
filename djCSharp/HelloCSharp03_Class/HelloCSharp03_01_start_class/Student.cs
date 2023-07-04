using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp03_01_start_class
{
    public class Student
    {
        //속성
        public int age; //인스턴스 변수
        public string name;
        //c#에서는 getter, setter가 있을까?
        public string hakbeon { get; set; }//dataGridView에선 필수!

        private string hp;
        public string phoneNumber
        {
            get { return hp; }
            set { hp = value; }
        }
    }
}
