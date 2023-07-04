using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp03_01_start_class
{
    public class KBStudent : Student
    {
        //인스턴스 변수
        //인스턴스별로 다 다른 것
        //new KBStudent() 할 때 메모리에 올라감
        public string gender { get; set; }
        public int money { get; set; }

        //motto는 static이 붙음
        //static이 붙은 걸 클래스 변수
        //이건 상속 여부를 떠나서 모두 다 공통적으로 접근하고
        //공통적으로 쓰는 데이터
        //프로그램이 시작하자마자 바로 메모리에 올라감
        public static string motto = "우분투정신";
    }
}
