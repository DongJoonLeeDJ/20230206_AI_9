using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp01_Start
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //Write = 개행없음(한 줄 띄우기 없음)
            Console.Write("Write");
            //WriteLine = 자동으로 줄띄움해줌
            Console.WriteLine("WriteLine");
            //ctrl + d : 한 줄 복사 & 붙여넣기
            Console.WriteLine("WriteLine");
            Console.WriteLine("WriteLine");
            //alt + shift + 화살표 위 or 아래
            //동시 선택
            Console.Write("Write");
            Console.Write("Write"); //ctrl+x : 잘라내기
        }
    }
}
