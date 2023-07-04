using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp03_02_default_class
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Random r = new Random();
            //1부터 20까지의 값을 랜덤하게 줌
            //Next라는 기능은 Random 객체 안에 있는 것
            Console.WriteLine(r.Next(1,21));

            //java의 ArrayList랑 동일하다고 보면 됨
            List<int> numList = new List<int>();
            numList.Add(10);
            numList.Add(20);
            numList.RemoveAt(0);
            numList.Add(30);
            numList.Remove(20);
            numList.Add(40);
            foreach (var item in numList)
            {
                Console.WriteLine(item);
            }

            Student[] students = new Student[3];
            List<Student> mystudents= new List<Student>();
            mystudents.Add(new Student());
            mystudents[0].name = "이수성";
            mystudents[0].age = 25;
            mystudents[0].grade = 4;
            mystudents.Add(new Student() { age=59,grade=1,name="정홍근"});

            Student g = new Student() { age = 22, name = "안교석", grade = 2 };
            Student l = new Student();
            l.name = "이동준";
            l.age = 34 ;
            l.grade = 6;
            mystudents.Add(g);
            mystudents.Add(l);

            students[0] = g;
            students[1] = l;
            students[2] = mystudents[0];



        }
    }
}
