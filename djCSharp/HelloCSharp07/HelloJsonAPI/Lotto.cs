using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloJsonAPI
{
    public class Lotto
    {
        public string drwtNo1 { get; set; }//1번째 자리
        public string drwtNo2 { get; set; }//2번째 자리
        public string drwtNo3 { get; set; }//3번째 자리
        public string drwtNo4 { get; set; }//4번째 자리
        public string drwtNo5 { get; set; }//5번째 자리
        public string drwtNo6 { get; set; }//6번째 자리
        public string bnusNo { get; set; }//보너스번호
        public string drwNo { get; set; }//회차

        public Lotto(string drwtNo1, string drwtNo2, string drwtNo3, string drwtNo4, string drwtNo5, string drwtNo6, string bnusNo, string drwNo)
        {
            this.drwtNo1 = drwtNo1;
            this.drwtNo2 = drwtNo2;
            this.drwtNo3 = drwtNo3;
            this.drwtNo4 = drwtNo4;
            this.drwtNo5 = drwtNo5;
            this.drwtNo6 = drwtNo6;
            this.bnusNo = bnusNo;
            this.drwNo = drwNo;
        }
    }
}
