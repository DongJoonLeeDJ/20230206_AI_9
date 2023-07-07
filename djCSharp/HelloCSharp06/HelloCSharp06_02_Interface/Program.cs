using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp06_02_Interface
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //정수를 여러 개 만들고 정렬해보기
            List<int> list = new List<int>();
            list.Add(5);
            list.Add(1);
            list.Add(list.Count);
            foreach(var item in list)
            {
                Console.WriteLine(item);    
            }
            list.Sort();

            foreach (var item in list)
            {
                Console.WriteLine(item);
            }

            //상품을 여러 개 만들고 정렬해보기
            List<Product> products = new List<Product>();
            products.Add(new Product() {name="감자",Id=5,price=500 });
            products.Add(new Product() {name="고구마",Id=3,price=5000 });
            products.Add(new Product() {name="파",Id=1,price=3000 });

            products.Sort();

            foreach(var item in products)
                Console.WriteLine(item);//item.ToString()

            DogBot b1 = new DogBot();
            b1.age = 15;
            b1.alias = "니니";
            b1.name = "말티즈";
            b1.serialNum = "000000";

            DogBot b2 = new DogBot();
            b2.age = 1;
            b2.alias = "뭉치";
            b2.name = "슈나우저";
            b2.serialNum = "2023";

            List<DogBot> bots = new List<DogBot>();
            bots.Add(b2);
            bots.Add(b1);
            foreach (var item in bots)
                Console.WriteLine(item.name + " " + item.age);
            bots.Sort();

            foreach(var item in bots)
                Console.WriteLine(item.name+" "+item.age);

            //인터페이스로도 다형성 구현 가능
            //왼쪽은 인터페이스나 조상클래스가 오고
            //오른쪽은 그걸 구현한 클래스 혹은 자손 클래스가 온다.
            IPet p = new DogBot();
            List<IPet> pp = new List<IPet>();
            pp.Add(b1);
            pp.Add(b2);
            

        }
    }
}
