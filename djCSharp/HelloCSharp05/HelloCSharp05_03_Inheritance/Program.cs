using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp05_03_Inheritance
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Student s= new Student();
            s.study();
            s.sleep();

            ESportStudent es = new ESportStudent();
            es.study();
            es.shotGun();
            es.sleep();

            Food f = new Gimbap();
            f.name = "이수성네 김밥";
            f.price = 500000;
            f.leaveFood();
            List<Food> foods = new List<Food>();
            foods.Add(f);
            foods.Add(new Gimbap());
            foods.Add(new Naengmyeon());

            foods[0].Eat();
            foods[1].Eat();
            foods[2].Eat();
        }
    }
}
