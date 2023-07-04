using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp02_Statement_Loop
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int a = 1;
            switch (a)
            {
                case 1:
                case 2:
                    Console.WriteLine("일!");
                    break;
                case 3://c,java에선 break 없어도 됨
                    //그러나 c#에선 밑에 문장을
                    //하나라도 적었다면 반드시
                    //break 필요!!!
                    Console.WriteLine("안녕하세요");
                    break;//중요!
                case 4:
                    break;
                default:
                    break;
            }
        }
    }
}
