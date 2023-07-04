using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp02_03_foreach
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] arr = { 1, 2, 3, 4 };
            int[] arr2 = new int[5];
            arr2[0] = -1;//처음
            arr2[4] = 100;//맨끝
            foreach (var item in arr)
            {
                Console.WriteLine(item);
            }
            foreach(int item in arr2)
            {
                Console.WriteLine(item);
            }
            for(int i = 0; i<arr.Length;i++)
                Console.WriteLine(arr[i]);
        }
    }
}
