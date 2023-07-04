using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp03_01_start_class
{
    //C의 구조체와는 다르게
    //메소드(=함수)도 추가할 수 있다.
    //그렇다면 class랑 어떤 점이 다를까?
    public struct Person
    {
        public string Name { get; set; }
        public int Age { get; set; }
        public int Cash { get; set; }
    }
}
