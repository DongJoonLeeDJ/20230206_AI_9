using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HelloCSharp04_02_method
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        //오버로딩
        //매개변수의 개수나 타입이 다르면 
        //메소드(=함수)의 이름이 똑같아도
        //서로 다른 기능으로 간주하는 것
        private int power(int num) 
        {
            //ulong temp = num;
            return num * num;
        }
        private int power(int num1, int num2)
        {
            return num1 * num2;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int n = int.Parse(textBox1.Text);
            label1.Text = power(n).ToString();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            int.TryParse(textBox2.Text, out int n1);
            int.TryParse(textBox3.Text, out int n2);
            label2.Text = power(n1,n2).ToString();

            Random r = new Random();
            int num = r.Next(10); //인스턴스 메소드
            int num2 = Math.Abs(-10); //Math클래스에 있는 클래스 메소드
        }

        private void button3_Click(object sender, EventArgs e)
        {

            //왼쪽에 조상클래스 적고
            //오른쪽에 자손클래스 적는 것 : 다형성
            Dog d1 = new Dog("풍돌이",10,"빨간색");
            Animal a = new Dog("털털이", 5, "흰색");

            d1.bark();
            (a as Dog).bark();

            //형변환 방법 3가지
            //1. as 키워드
            Dog temp = a as Dog;
            //2. is랑 as 병행
            if (a is Dog)
                temp = a as Dog;
            //3. 그냥 괄호
            temp = ((Dog)a);
            //4. as 타입으로 null 여부 체크한 뒤 변환
            temp = a as Dog == null ? null : a as Dog;

            //Animal List나 Animal 배열에 Dog, Cat등의
            //Animal 상속받은 클래스들이 들어갈 수 있다.

            Dog mydog 
                = new Dog(textBox_name.Text, 
                int.Parse(textBox_age.Text), 
                textBox_color.Text);
            mydog.bark();



        }
    }
}
