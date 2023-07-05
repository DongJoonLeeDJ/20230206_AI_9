using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp04_02_method
{
    public class Dog : Animal
    {
        //base = java의 super
        //조상 클래스
        //조상 클래스에 있는 생성자를 호출한 것

        public string hairColor { get; set; }
        public Dog(string name, int age) : base(name, age)
        {
        }

        public Dog(string name, int age,string hairColor): base(name, age)
        {
            this.hairColor = hairColor;
        }

        public void bark()
        {
            System.Windows.Forms.MessageBox.Show(this.hairColor);
            Console.WriteLine(this.name);
            Console.WriteLine(this.age);
        }
    }
}
