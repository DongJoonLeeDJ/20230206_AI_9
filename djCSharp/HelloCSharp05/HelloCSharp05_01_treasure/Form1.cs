using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HelloCSharp05_01_treasure
{
    public partial class Form1 : Form
    {
        private int limitTime = 0;
        private int answer = 0;
        private int timer = 0;
        public Form1()
        {
            InitializeComponent();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            timer++;
            if(timer>limitTime || timer==-1)
            {
                label1.Text = "Game Over!!!";
                timer = 0;
                timer1.Enabled = false;//타이머를 멈춘다.
            }

        }

        private void button1_Click(object sender, EventArgs e)
        {
            //if (int.TryParse(textBox1.Text, out limitTime) == false)
            if (!int.TryParse(textBox1.Text, out limitTime))
            {
                timer = 0;
                timer1.Enabled = false;
                label1.Text = "제한 시간을 제대로 입력해주세요.";
                return;
            }
            if(limitTime <= 0)
            {
                timer = 0;
                timer1.Enabled = false;
                label1.Text = "제한 시간을 제대로 입력해주세요.";
                return;
            }

            label1.Text = "Game Start!";
            timer1.Enabled = false;//일단 타이머 멈춤
            timer = 0;
            answer = new Random().Next(1, 26);//1~25까지의 값
            Console.WriteLine("answer="+answer);
            int count = 1; //순차적으로 text 써줄 것
            for(int i = 0; i<5; i++)
            {
                for(int j = 0; j<5; j++)
                {
                    Button btn = new Button();//클릭할 버튼
                    Point pt = new Point();//위치(=좌표)
                    pt.X = 10 + 100 * j;
                    pt.Y = 25 + 25 * i;
                    btn.Location = pt;
                    btn.Click += BtnClick;//이벤트 추가
                    btn.Text = count + "";
                    count++;
                    Controls.Add(btn);
                }
            }
            timer1.Enabled = true;

        }

        //코드로 만든 버튼에서 사용할 이벤트
        private void BtnClick(object sender, EventArgs e)
        {
            if( (sender as Button ).Text.Equals(answer.ToString()))
            {
                label1.Text = "승리!";
                timer = 0;
                timer1.Enabled = false;
            }
            else
            {
                label1.Text = "이건 보물이 아닙니다.";
            }

        }
    }
}
