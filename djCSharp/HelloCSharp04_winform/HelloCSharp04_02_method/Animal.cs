using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp04_02_method
{
    public class Animal
    {
        public string name { get; set; }
        public int age { get; set; }

        //java와 마찬가지로 생성자가 없으면
        //빈 생성자 public Animal(){} 이런 게 자동으로 있다.
        //근데 생성자를 명시적으로 추가하면 이런 빈 생성자가
        //없어진다.
        //그래서 이렇게 생성자를 새로 추가한 상태에서
        //빈 생성자를 쓰고 싶으면, 만들어야 한다.

        //생성자나 메소드에 대해서 오버로딩
       // public Animal() { }
        public Animal(string name, int age)
        {
            this.name = name;
            this.age = age;
        }
    }
}
