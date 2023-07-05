using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HelloCSharp04_winform
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            List<Student> students = new List<Student>();
            students.Add(new Student() { name="이동준",grade=1,age=34});
            students.Add(new Student() { name="김신혁",grade=2,age=27});
            students.Add(new Student() { name="김희수",grade=3,age=25});
            students.Add(new Student() { name = "박세진", grade = 4, age = 62 });
            students.Add(new Student() { name = "박준호", grade = 5, age = 34 });
            students.Add(new Student() { name = "소병수", grade = 1, age = 33 });


            //길이
            //배열에선 .length를 사용
            //List에선 .Count를 사용함
            for(int i = 0; i<students.Count; i++)
            {
                Label label = new Label();
                label.Text = $"{students[i].name}학생, {students[i].age}살";
                label.AutoSize = true; //글자 길이에 따라 사이즈 늘어남
                label.Location = new Point(10,10+35*i);
                Controls.Add(label); //이걸 해줘야 우리 눈에도 보임
                //Controls = Form1 안에 있는 모든 컴포넌트들
                //컴포넌트 = 구성요소 = ex:버튼, 텍스트박스 등...
            }

            //1. ctrl f5 말고 f5눌러서(=디버깅 모드)에서
            //창에서 보는 방법
            //2. 콘솔창도 같이 보도록 설정을 해서 보는 방법
            foreach(Student student in students) 
            {
                Console.WriteLine("이름:"+student.name);
                Console.WriteLine(student.grade+"학년");
                Console.WriteLine(student.age+"살");
            }

            //students에서 1학년만 남길 것
            //반복문 돌리면서 뭔가를 삭제해갈 것이라면
            //반드시 역for문을 돌려야 함
            //그냥 for문 돌리면 outOfIndex에러남(인덱스 오버플로)

            for(int i = students.Count-1; i>=0; i--) 
            {
                if (students[i].grade>1)
                    students.RemoveAt(i); //해당 번째꺼 지워버림
            }
            for (int i = 0; i < students.Count; i++)
            {
                Label label = new Label();
                label.Text = $"{students[i].name}학생, {students[i].age}살";
                label.AutoSize = true; //글자 길이에 따라 사이즈 늘어남
                label.Location = new Point(150, 10 + 35 * i);
                Controls.Add(label); //이걸 해줘야 우리 눈에도 보임
                //Controls = Form1 안에 있는 모든 컴포넌트들
                //컴포넌트 = 구성요소 = ex:버튼, 텍스트박스 등...
            }
            students.Add(new Student());
            students[students.Count - 1].name = "송준희";
            students[students.Count - 1].age=42;
            students[students.Count - 1].grade=1;

            Student s = new Student();
            s.name = "신동훈";
            s.age = 29;
            s.grade = 1;
            students.Add(s);

            Student ss = new Student() { name="안교석",age=22,grade=1};
            students.Add(ss);

            for(int i = students.Count-1; i>=0; i--) 
            {
                //if (students[i].age>30)
                if (students[i].age < 40)
                    students.RemoveAt(i);
            }
            for (int i = 0; i < students.Count; i++)
            {
                Label label = new Label();
                label.Text = $"{students[i].name}학생, {students[i].age}살";
                label.AutoSize = true; //글자 길이에 따라 사이즈 늘어남
                label.Location = new Point(300, 10 + 35 * i);
                Controls.Add(label); //이걸 해줘야 우리 눈에도 보임
                //Controls = Form1 안에 있는 모든 컴포넌트들
                //컴포넌트 = 구성요소 = ex:버튼, 텍스트박스 등...
            }

        }
    }
}
