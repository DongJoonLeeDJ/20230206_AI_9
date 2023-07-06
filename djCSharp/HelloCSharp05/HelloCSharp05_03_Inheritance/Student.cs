using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp05_03_Inheritance
{
    public class Student
    {
        public virtual void study()
        {
            Console.WriteLine("학생이니까 공부합니다.");
        }
        public void sleep()
        {
            Console.WriteLine("학생도 잠은 자야죠");
        }
    }
}
