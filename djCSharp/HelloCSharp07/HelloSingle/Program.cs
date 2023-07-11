using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloSingle
{
    internal class Program
    {

        static string hak;
        static bool FindStudent(Student s)
        {
            return s.hakbeon == hak; 
        }

        static void Main(string[] args)
        {
            List<Student>  students = new List<Student>();
            students.Add(new Student() { hakbeon="01",name="임나현",age=20});
            students.Add(new Student() { hakbeon="00",name="안교석",age=22});
            students.Add(new Student() { hakbeon="02",name="김희수",age=25});
            students.Add(new Student() { hakbeon="03",name="송준희",age=41});
            //students.Add(new Student() { hakbeon="00",name="소병수",age=41});

            //특정 학번의 학생을 찾을 것(입력받을 것)
            //그 학생의 이름을 바꿀 것
            //1. 함수 방식(for문)
            try
            {
                Console.WriteLine("원하는 학번은?");
                hak = Console.ReadLine();
                for(int i = 0; i<students.Count; i++) 
                {
                    if (FindStudent(students[i]))
                    {
                        Console.WriteLine(students[i].name);
                        Student temp = students[i];//temp는 students[i]의 값을
                        //가져왔다기보다는 students[i]의 참조를 한 것(위치를 참조)
                        temp.name = "신동훈";
                        Console.WriteLine(students[i].name);
                    }
                }
                Console.WriteLine("-함수방식1-");
                //1. 함수 방식(Single)
                Console.WriteLine("원하는 학번을 입력.");
                hak = Console.ReadLine() ;  
                Student mytemp = students.Single(FindStudent);
                Console.WriteLine(mytemp.name);
                Console.WriteLine("해당 학번 학생의 이름을 변경해보세요.");
                Console.WriteLine("변경된 이름(hak="+hak+")");
                mytemp.name = Console.ReadLine(); //students에 직접 영향줌
                Console.WriteLine("전체 출력");
                foreach(var item in students)
                    Console.WriteLine(item.name);
                //2. 무명 델리게이트 방식
                Console.WriteLine("-2-무명델리게이트");
                Console.WriteLine("hak="+hak);
                Student ss = students.Single(delegate(Student a)
                {
                    return a.hakbeon == hak;
                });

                Console.WriteLine("-2-무명델리게이트 검색된 이름");
                Console.WriteLine(ss.name);
                ss.name = "임시이름";
                Console.WriteLine("다시 출력(2)");
                foreach (var item in students)
                    Console.WriteLine(item.name);
                //3. 람다 방식
                Console.WriteLine("-3 람다방식-");
                Student sss = students.Single(a => a.hakbeon == hak);
                Console.WriteLine("-검색된 이름 출력-");
                Console.WriteLine(sss.name);
                sss.name = "임나현;;;";
                Console.WriteLine("최종 결과");
                foreach (var item in students)
                    Console.WriteLine(item.name);


                students.Remove(sss); //내가 입력한 학번에 해당하는 학생이 지워짐
                //RemoveAt = index
                Console.WriteLine("해당 학생 지우고 난 뒤의 전체 결과");
                foreach (var item in students)
                    Console.WriteLine(item.name);

                //Single = 단하나만 찾는 것
                //하나도 없거나 두 개 이상이면 Exception발생


            }
            catch (Exception ex) //Single은 없는 걸 찾으려고 하면 catch로 빠짐
            {
                Console.WriteLine(ex.Message);
                Console.WriteLine(ex.StackTrace);
            }

        }
    }
}
