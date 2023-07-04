using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp02_02_Array
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string[] arr =
                {"원숭이","닭","개","돼지",
            "쥐","소","범","토끼","용","뱀",
            "말","양"};

            //item = arr에 있는 값들을 의미
            //var = 처음에 선언하고 나서는 타입이 안 바뀜
            var a = 1;
            //a = "aaaa";
            var b = "bbb";
            //b = 2;
            foreach (var item in arr)
            {
                Console.WriteLine(item);
            }
            foreach(string item in arr)
                Console.WriteLine(item);

            for(int i = 0; i<arr.Length;i++)
                Console.WriteLine(arr[i]);

            string[] arr2 = new string[12];
            arr2[0] = arr[0];
            arr2[1] = "닭";

            int year = 1989;
            Console.WriteLine(arr[year%12]);

        }
    }
}
