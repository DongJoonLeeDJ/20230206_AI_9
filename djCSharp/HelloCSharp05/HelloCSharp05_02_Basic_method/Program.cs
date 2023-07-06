using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp05_02_Basic_method
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Calculator c = new Calculator();
            c.name = "Test";
            Console.WriteLine("파이값 : " + Calculator.PI);
            Console.WriteLine(c.Power(10));
            Console.WriteLine(Calculator.Power((char)4));
            Console.WriteLine(Calculator.Power((char)0));
            Console.WriteLine(Calculator.Power('\0'));
            Console.WriteLine(Calculator.Power('A'));//65의 제곱
            Console.WriteLine(Calculator.Power('0'));
            Console.WriteLine(c.Power(3,3));
            Console.WriteLine(c.Power(3,4));
            Console.WriteLine(Calculator.SumAll(10));//0~10까지합
            Console.WriteLine(Calculator.SumAll(5,10));//5~10까지의 합

        }
    }
}
