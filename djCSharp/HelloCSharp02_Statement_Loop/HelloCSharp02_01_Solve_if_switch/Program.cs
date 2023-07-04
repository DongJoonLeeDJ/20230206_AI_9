using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp02_01_Solve_if_switch
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("몇년생인가요?");
            int year = int.Parse(Console.ReadLine());
            //1989 = 뱀띠 = %12 = 9
            int mythee = year % 12; //12로 나눈 나머지
            if(mythee==0)
                Console.WriteLine("원숭이띠");
            else if(mythee==1)
                Console.WriteLine("닭띠");
            else if (mythee == 2)
                Console.WriteLine("개띠");
            else if (mythee == 3)
                Console.WriteLine("돼지띠");
            else if (mythee == 4)
                Console.WriteLine("쥐띠");
            else if (mythee == 5)
                Console.WriteLine("소띠");
            else if (mythee == 6)
                Console.WriteLine("호랑이띠");
            else if (mythee == 7)
                Console.WriteLine("토끼띠");
            else if (mythee == 8)
                Console.WriteLine("용띠");
            else if (mythee == 9)
                Console.WriteLine("뱀띠");
            else if (mythee == 10)
                Console.WriteLine("말띠");
            else
                Console.WriteLine("양띠");


            int nowThee = DateTime.Now.Year % 12;
            switch (nowThee)
            {
                case 0:
                    Console.WriteLine("원숭이띠");
                    break;
                case 1:
                    Console.WriteLine("닭띠");
                    break;
                case 2:
                    Console.WriteLine("개띠");
                    break;
                case 3:
                    Console.WriteLine("돼지띠");
                    break;
                case 4:
                    Console.WriteLine("쥐띠");
                    break;
                case 5:
                    Console.WriteLine("소띠");
                    break;
                case 6:
                    Console.WriteLine("호랑이띠");
                    break;
                case 7:
                    Console.WriteLine("토끼띠");
                    break;
                case 8:
                    Console.WriteLine("용띠");
                    break;
                case 9:
                    Console.WriteLine("뱀띠");
                    break;
                case 10:
                    Console.WriteLine("말띠");
                    break;
                case 11:
                    Console.WriteLine("양띠");
                    break;
            }

            Console.WriteLine("몇 월생?");
            int mymonth = int.Parse(Console.ReadLine());
            if(mymonth==12 || mymonth==1 || mymonth==2)
                Console.WriteLine("겨울");
            else if(mymonth>=3 && mymonth<=5)
                Console.WriteLine("봄");
            else if(mymonth == 6 || mymonth == 7 || mymonth==8)
                Console.WriteLine("여름");
            else if(mymonth >=9 && mymonth<=11)
                Console.WriteLine("가을");
            else
                Console.WriteLine("어느 별에서 왔니?");

            int myNowMonth = DateTime.Now.Month;
            switch (myNowMonth)
            {
                case 12:
                case 1:
                case 2:
                    Console.WriteLine("겨울");
                    break;
                case 3:
                case 4:
                case 5:
                    Console.WriteLine("봄");
                    break;
                case 6:
                case 7:
                case 8:
                    Console.WriteLine("여름");
                    break;
                case 9:
                case 10:
                case 11:
                    Console.WriteLine("가을");
                    break;
                default: //0, 13 이런 게 나올리가 없다.
                    Console.WriteLine(myNowMonth+"???");
                    break;
            }
        }
    }
}
