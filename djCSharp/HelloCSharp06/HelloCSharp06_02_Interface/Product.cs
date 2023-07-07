using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp06_02_Interface
{

    //만약 Product가 여러 개 있을 경우
    //Sort함수를 호출하게 되면 어떻게 정렬을 할까?
    public class Product : IComparable<Product>
    {
        public int Id { get; set; } //상품 고유번호
        public string name { get; set; }//상품 이름
        public int price { get; set; }//상품 가격 정보

        public int CompareTo(Product other)
        {
            //가격이 더 크냐 작냐 같냐에 따라서 
            //양수 0 음수 중 하나가 나옴
           return price.CompareTo(other.price);
        }

        //Object에 있는 ToString을 오버라이드하는 거 가능
        public override string ToString()
        {
            return $"id={Id}, 상품명={name}, 가격={price}";
        }

    }
}
