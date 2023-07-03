using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp02_Basic
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //int, bool, char
            //float, double, string
            //bool = boolean
            bool a = true;
            bool b = false;
            char c = '가';
            Console.WriteLine(c);
            string s = "이동준";
            Console.WriteLine(s);
            char c2 = s[0]; //제일 첫번째 글자 갖고 옴
            Console.WriteLine(c2);
            Console.WriteLine(s[1]);

            var temp = 1; //오른쪽에 있는 걸로
            //그 변수의 타입을 결정함
            //js의 var랑 다른거임
            //한 번 타입 정해지면 그 뒤론
            //타입은 못 바꾸고 값은 바꿀 수 있음
            temp = 5;
            //temp = "이동준"; //타입이 한 번 정수로 지정됐기 때문
            var temp2 = "이동준";
            //temp2 = 123;

            Console.WriteLine("이름이 뭐니?");
            string name = Console.ReadLine();
            //정수나 실수는 다른 방식 사용
            Console.WriteLine("올해는 몇년도?");
            int year = int.Parse(Console.ReadLine());
            //double.Parse를 이용하면 실수 입력 가능함
            //값을 문자열로 바꾸는 법
            name = year + "";
            name = year.ToString();
            name = 1989.ToString();


            //Console.ReadLine();
            //int.Parse(Console.ReadLine());
            //int.TryParse(Console.ReadLine(), out int ex);
        }
    }
}
