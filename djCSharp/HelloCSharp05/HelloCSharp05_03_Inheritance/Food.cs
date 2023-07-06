using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp05_03_Inheritance
{
    //추상화된 개념을 만들 때 주로 쓰임
    //Food a = new Food(); //불가능
    //Food a = new Gimbap();//단 Gimbap이
    //Food의 후손이어야 함
    public abstract class Food
    {
        public string name { set; get; }
        public int price { get; set; }
        public abstract void Eat();
        public void leaveFood()
        {
            Console.WriteLine(name+"못먹겠다.");
            Console.WriteLine(price+"값이 아깝다.");
        }

    }
}
