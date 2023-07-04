using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp02_05_Solve_Ant
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //1 11 12 1121 122111 112213
            string start = "1";
            for(int i = 0; i<20; i++)
            {
                Console.WriteLine($"{i+1}번째 : {start}");
                string end = "";
                char num = start[0]; //읽을 값
                int count = 0; //읽은 값의 개수
                for(int j = 0; j<start.Length;j++)
                {
                    if (start[j] != num)
                    {
                        end = end + num + count;
                        num = start[j];
                        count = 1;
                    }
                    else
                        count++;
                }
                end = end + num + count;
                start = end;
            }
        }
        /* 디버깅 하기*/
        //ctrl+f5 말고 f5 눌러야 함
        //숫자 옆에 점 찍거나 해당 라인에 대고 f9 누르기
        //빨간점 = break point
        //해당 시점의 값을 마우스 올려놓고 조사하거나
        //밑에 있는 조사식 이용해서 값을 보면 됨
        //f5 눌려진 상태에서
        //디버그->창->조사식->조사식 1~4중 하나 선택하기
    }
}
