using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp06_02_Interface
{
    public class DogBot : IRobot, IPet, IComparable<DogBot>
    {
        public string serialNum { get; set; }
        public string name { get; set ; }
        public string alias { get; set; }
        public int age { get; set; }

        public void charm()
        {
            Console.WriteLine("멍멍 주인님 사랑해요");
        }

        public int CompareTo(DogBot other)
        {
            return other.age.CompareTo(age);
        }

        public void eStop()
        {
            Console.WriteLine("휴머어어어언....으아어...");
        }

        public void run()
        {
            Console.WriteLine("멍멍! 달립니다!");
        }

        public void sayHello()
        {
            Console.WriteLine("충전해주세요 닝겐");
        }
    }
}
