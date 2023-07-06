using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp05_03_Inheritance
{
    public class Naengmyeon : Food
    {
        public override void Eat()
        {
            Console.WriteLine("호로록 호로록 식초넣고 먹는다.");
            Console.WriteLine("끓여먹지 않습니다.");
        }
    }
}
