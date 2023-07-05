using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace HelloCSharp04_01_random
{
    public partial class Form1 : Form
    { //C의 전역변수(글로벌변수)처럼 동작할 것
        int answer = 0;//answer는 Form1의 멤버변수
        //인스턴스 변수이기도 하며
        //앞에 접근제한자가 없으므로 private이 내정된 것
        public Form1() //생성자
        {
            InitializeComponent();
            Random r = new Random();
            answer = r.Next(1, 11);//1~10까지의 랜덤
            Console.WriteLine(answer);

            button2.Text = "가위";
            button3.Text = "바위";
            button4.Text = "보";
        }
       

        //메소드(=함수)
        //object sender = 이벤트를 발생시키는 주체
        private void button1_Click(object sender, EventArgs e)
        {
            //TryParse
            //문자열을 정수로 바꿔줌
            //실패하면 프로그램이 튕기진 않고 해당 변수에 0 대입
            //TryParse라는 함수 자체는 false를 리턴

            //참고 visual studio 2015까지는 out int는 안 되고
            //밖에 int 선언하고 out 변수명 이렇게 써야 했음
            //int m;
            //int.TryParse(textBox1.Text, out m);
            int.TryParse(textBox1.Text, out int mychoice);

            if(mychoice==answer)
            {
                MessageBox.Show("정답!");
                int prev = answer;//이전 정답
                answer = new Random().Next(1, 11);
                while(prev==answer)
                    answer = new Random().Next(1, 11);//중복 안 되게 하기
                Console.WriteLine(answer);
                return; //함수 종료
            }
            //여기로 넘어왔다는 건... 정답을 못 맞춘 것
            MessageBox.Show(mychoice+"는 오답!");

        }

        private void playRCP(object sender, EventArgs e)
        {
            Button temp = (sender as Button);
            string result = temp.Text;
            int computer = new Random().Next(3);//0이상 3미만
            string[] rcp = { "가위", "바위", "보" };
            string computerResult = rcp[computer];

            //가위 바위 보의 승부 결과를 rcpresult로 리턴함
            string rcpresult = goRCP(result, computerResult);
            label1.Text = $"나:{result}\n" +
                $"컴퓨터:{computerResult}\n" +
                $"결과 : {rcpresult}";
        }

        private string goRCP(string result, string computerResult)
        {
            if (result.Equals(computerResult))
                return "비김";
            else //둘이 다른 경우
            {
                switch(result)
                {
                    case "가위":
                        if (computerResult.Equals("바위"))
                            return "패배";
                        else
                            return "승리";
                        //break;

                    case "바위":
                        if (computerResult.Equals("보"))
                            return "패배";
                        else
                            return "승리";
                       //break;

                    case "보":
                        if (computerResult.Equals("가위"))
                            return "패배";
                        else
                            return "승리";
                       // break;
                }
            }
            return "판정불가"; //이도 저도 아닌 경우
            //throw new NotImplementedException();
        }

        List<string> sentenses = new List<string>(){ "a","b","c"};
        private void button5_Click(object sender, EventArgs e)
        {
            label2.Text = sentenses[new Random().Next(sentenses.Count)];
        }
    }
}
