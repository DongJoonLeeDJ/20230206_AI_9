using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp05_02_Basic_method
{
    public class Calculator
    {
        //인스턴스 변수
        //계산기별 이름은 다 다르다고 가정
        public string name { get; set; }

        //클래스 변수(공통됨)
        public static double PI = 3.14;


        //인스턴스 별로 다르게 실행이 가능
        //인스턴스를 만들어야지만 실행
        public int Power(int input)
        {
            Console.WriteLine(name+"계산기의 제곱 기능 수행");
            return input * input;
        }
        //클래스이름.메소드명() 이렇게 바로 실행가능
        public static int Power(char input)//오버로딩해주려고 char씀
        {
            return input * input;
        }

        public int Power(int input, int count)
        {
            Console.WriteLine(name+"계산기의 거듭제곱");
            //input을 Count만큼 제곱
            int result = input;
            for(int i = 1; i< count; i++) 
            {
                result *= input;
            }
            return result;

        }

        public static int SumAll(int end) //0부터 end사이 모든 정수 합
        {
            int sum = 0;
            for (int i = 0; i <= end; i++)
                sum += i;
            return sum;
        }
        public static int SumAll(int start, int end)
        {
            int sum = 0;
            for (int i = start; i <= end; i++)
                sum += i;
            return sum;
        }
    }
}
