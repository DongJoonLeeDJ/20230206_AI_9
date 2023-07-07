using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HelloCSharp06_06_delegate_lambda
{
    public partial class Form1 : Form
    {

        List<Student> students = new List<Student>();   
        public Form1()
        {
            InitializeComponent();
            students.Add(new Student("이동준", 34));
            students.Add(new Student("송준희", 42));
            students.Add(new Student("김희수", 25));

            //오름 차순 : 김희수 이동준 송준희
            //내림 차순 : 송준희 이동준 김희수

            Button btn = new Button();
            btn.Location = new Point(150, 100);
            btn.Text = "내가만든거";
            btn.AutoSize = true;
            btn.Click += Btn_Click;
            Controls.Add(btn);
            Button btn2 = new Button();
            btn2.Location = new Point(150, 150);
            btn2.Text = "람다";
            btn2.AutoSize = true;
            btn2.Click += (sender, e) => {
                MessageBox.Show((sender as Button).Text);
            };
            Controls.Add(btn2);

            Button btn3 = new Button();
            Controls.Add(btn3);
            btn3.Text = "무명델리";
            btn3.Location = new Point(150, 250);
            btn3.Click += delegate (object sender, EventArgs e)
            {
                MessageBox.Show("sender = 이 버튼");
            };
            btn3.Click += Btn_Click;
            //btn3는 한 번 클릭해서 두 번의 메소드가 호출됨
        }

        private void Btn_Click(object sender, EventArgs e)
        {
            MessageBox.Show("안녕~");
        }

        //델리게이트 = 대리자
        //함수를 변수화시킴
        //일종의 자료형
        delegate int calculator(int x, int y);

        int add(int x,int y)
        {
            return x + y;
        }
        int sub(int x, int y)
        {
            return x - y;
        }

        void showCalc(calculator c, int x, int y)
        {
            MessageBox.Show("연산 결과 : " + c(x,y));
        }

        private void button1_Click(object sender, EventArgs e)
        {
            showCalc(add, 10, 20);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            showCalc(sub, 10, 20);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            //즉석에서 만든 함수
            //무명 델리게이트
            showCalc(delegate (int x, int y) { return x * y; }, 10, 20);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            //무명 델리게이트를 더 줄이면 람다
            showCalc((x, y) => { return x / y; }, 30, 10);
        }

        private void button5_Click(object sender, EventArgs e)
        {
            //students.Sort(); //에러 남. 뭘 기준으로 정렬할 지 모름
            students.Sort((a, b) => { return a.age.CompareTo(b.age);  }  );
            string show = "";
            foreach (var item in students)
                show += item.name;
            MessageBox.Show(show);
        }

        private void button6_Click(object sender, EventArgs e)
        {
            students.Sort(delegate (Student a, Student b) {
                return b.age.CompareTo(a.age);
            });
            string show = "";
            foreach (var item in students)
                show += item.name;
            MessageBox.Show(show);
        }

        int orderByAge(Student a, Student b)
        {
            return a.age.CompareTo(b.age);
        }
        int orderByDesc(Student b, Student a)
        {
            return a.age.CompareTo(b.age);
        }

        private void button7_Click(object sender, EventArgs e)
        {
            students.Sort(orderByAge);
            string show = "";
            foreach (var item in students)
                show += item.name;
            MessageBox.Show(show);
        }

        private void button8_Click(object sender, EventArgs e)
        {
            students.Sort(orderByDesc);
            string show = "";
            foreach (var item in students)
                show += item.name;
            MessageBox.Show(show);
        }

        private void button9_Click(object sender, EventArgs e)
        {
            calculator a = add;
            calculator b = sub;
            calculator c = delegate (int x, int y)
            {
                return x * y;
            };
            calculator d = (x, y) => { return x / y;  };
            int num1 = a(100, 200);
            int num2 = b(200, 5);
            int num3 = c(20, 30);
            int num4 = d(9, 3);
            MessageBox.Show("값들 " + num1+","+num2 + 
                "," + num3 + "," + num4);
        }

        void printStringA()
        {
            for (int i = 0; i < 100; i++)
                Console.Write("A");
        }

        private void button10_Click(object sender, EventArgs e)
        {
            //Thread = 실행 단위
            //하나의 프로세스 = 여러 개의 Thread
            //하나의 프로세스 = 하나의 프로그램 실행 단위
            //Thread의 특이사항 : 동시에 실행이 가능하다

            //일반적으로는 메소드1이 실행중이면
            //메소드1이 끝나야지 메소드2가 실행됨

            //Thread에 메소드1을 담아서 실행하다가
            //시분할 알고리즘에 의해서 메소드2가 실행됨
            //그러다가 메소드2가 느려질 때쯤 메소드1이나 메소드3가 실행됨

            //한 번에 하나만 실행(컴퓨터, 사람)
            Thread a = new Thread(printStringA);
            Thread b = new Thread(delegate ()
            {
                for(int i = 0; i<100; i++)
                    Console.Write("B");
            });
            Thread c = new Thread(() =>
            {
                for (int i = 0; i < 100; i++)
                    Console.Write("C");
            });
            a.Start();
            b.Start();
            c.Start();
        }
    }
}
