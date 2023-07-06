using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp05_03_Inheritance
{
    public class Gimbap : Food
    {
        public override void Eat()
        {
            Console.WriteLine("돌돌 말아서 먹는다.");
            //throw new NotImplementedException();
        }
    }
}
