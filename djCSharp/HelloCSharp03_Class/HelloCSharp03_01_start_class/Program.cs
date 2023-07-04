using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp03_01_start_class
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Student s = new Student();
            s.phoneNumber = "010-1234-4321";
            s.name = "서정빈";
            s.age = 20;
            s.hakbeon = "2009038";
            Console.WriteLine(s.phoneNumber);

            KBStudent kb = new KBStudent();
            KBStudent kkb = new KBStudent();
            kkb.age = 25;
            kkb.name = "안교석";

            kb.age = 30;
            kb.name = "소병수";
            kb.hakbeon = "2020012";
            kb.phoneNumber = "없음";
            kb.gender = "여성"; //KBStudent에만 있음
            kb.money = 5000;//단위 만원

            Person p = new Person();
            p.Age = 31;
            p.Name = "박준호";
            p.Cash = 900000;

            Console.WriteLine(kb.name);
            Console.WriteLine(kb.money);
            Console.WriteLine(p.Name);
            Console.WriteLine(p.Cash);

            //소병수라는 학생이 추가로 입학함
            //박준호라는 사람이 추가로 입주함
            //정보는 다 똑같은 데 돈 정보만 다름

            KBStudent kb2 = kb;//이름 성별 다 똑같음
            //핸드폰 번호랑 잔액만 다름
            kb2.money = -500;
            kb2.phoneNumber = "010-1111-2222";

            Person p2 = p;//박준호랑 동명이인
            p2.Age = 40;
            p2.Cash = 0;
            Console.WriteLine("---- class와 struct의 차이 ----");
            Console.WriteLine(kb.name);
            Console.WriteLine(kb.money);
            Console.WriteLine(kb.phoneNumber);
            Console.WriteLine(kb2.name);
            Console.WriteLine(kb2.money);
            Console.WriteLine(kb2.phoneNumber);

            Console.WriteLine(p.Name);
            Console.WriteLine(p.Age);
            Console.WriteLine(p.Cash);

            Console.WriteLine(p2.Name);
            Console.WriteLine(p2.Age);
            Console.WriteLine(p2.Cash);

            //복사하는 방식 다름
            //struct는 int, string처럼 깊은 복사가 기본
            //class는 얕은 복사가 기본

            Console.WriteLine(KBStudent.motto);


        }
    }
}
