using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp03_Solve
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //inch 입력받아서 cm 단위 구하기
            Console.WriteLine("1번 문제");
            Console.WriteLine("몇 인치인가요?");
            int inch = int.Parse(Console.ReadLine());
            Console.WriteLine(inch+"inch="+(2.54*inch)+"cm");

            Console.WriteLine("2번 문제");
            Console.WriteLine("몇 kg?");
            int kg = int.Parse(Console.ReadLine());
            Console.WriteLine($"{kg}kg = {2.20462262*kg}pound");

            //상수
            //java = final
            //c,c++,c# = const
            const double PI = 3.14;
            Console.WriteLine("3번 문제");
            Console.WriteLine("원의 반지름은?");
            int r= int.Parse(Console.ReadLine());
            
            Console.WriteLine(string.Format("둘레={0}, 넓이={1}",2*PI*r, r*r*PI));

            Console.WriteLine("마지막 문제");
            string num1 = Console.ReadLine();
            string num2 = Console.ReadLine();
            int mynum1 = int.Parse(num1);
            int mynum2 = int.Parse(num2);
            //472, 385
            //나머지와 나누기로 푸는 방법
            Console.WriteLine(mynum1 * (mynum2%10));//472*5
            Console.WriteLine(mynum1 * ((mynum2/10)%10));//472*8
            Console.WriteLine(mynum1*(mynum2/100));//472*3
            Console.WriteLine(mynum1*mynum2);
            //문자열을 이용한 방법
            Console.WriteLine(mynum1* (num2[2]-'0'));
            Console.WriteLine(mynum1* (num2[1]-'0'));
            Console.WriteLine(mynum1* (num2[0]-'0'));
        
        }
    }
}
