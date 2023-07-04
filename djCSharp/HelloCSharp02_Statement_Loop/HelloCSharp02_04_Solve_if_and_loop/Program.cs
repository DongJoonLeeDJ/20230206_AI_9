using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp02_04_Solve_if_and_loop
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("1. 출력할 별의 높이는?");
            int floor = int.Parse(Console.ReadLine());
            for(int i = 0; i<floor;i++)
            {
                for(int j = floor-i-1; j>0; j--)
                    Console.Write(" ");
                for(int j = 0; j<2*i+1;j++)
                    Console.Write("*");
                Console.WriteLine(); //한 줄 띄기
            }
            //2번
            int a, b, c, d, e;
            Console.WriteLine("a는?");
            a =int.Parse(Console.ReadLine());
            Console.WriteLine("b는?");
            b = int.Parse(Console.ReadLine());
            Console.WriteLine("c는?");
            c = int.Parse(Console.ReadLine());
            Console.WriteLine("d는?");
            d = int.Parse(Console.ReadLine());
            Console.WriteLine("e는?");
            e = int.Parse(Console.ReadLine());

            int max = a;
            int min = a;

            if(max<b)
                max = b;
            if(min>b)
                min = b;


            if (max < c)
                max = c;
            if (min > c)
                min = c;


            if (max < d)
                max = d;
            if (min > d)
                min = d;


            if (max < e)
                max = e;
            if (min > e)
                min = e;

            Console.WriteLine("최대 : " + max);
            Console.WriteLine("최소 : " + min);

        }
    }
}
