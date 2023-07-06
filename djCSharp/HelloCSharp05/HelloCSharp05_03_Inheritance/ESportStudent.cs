using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp05_03_Inheritance
{
    public class ESportStudent : Student
    {
        public override void study()
        {
            Console.WriteLine("열심히 컴퓨터로 게임 공부 해요");
            //base = java의 super
            //base.study();//조상 클래스의 study를 호출
        }
        public void shotGun()
        {
            Console.WriteLine("으아 학원 바까줘 아아");
        }
    }
}
