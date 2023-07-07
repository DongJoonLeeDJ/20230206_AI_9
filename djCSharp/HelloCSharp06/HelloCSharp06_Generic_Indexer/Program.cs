using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp06_Generic_Indexer
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Employee<int> employee = new Employee<int>();
            Employee<string> emp = new Employee<string>();

            List<Employee<int>> employeeList =
                new List<Employee<int>>();

            List<Employee<Object>> a  =
                new List<Employee<Object>>();

            employee.name = "김희수";
            employee.age = 25;
            employee.sabeon = 1;

            employeeList.Add(employee);
            employeeList.Add
                (new Employee<int>() 
                { age=34,name="이동준",sabeon=0});

            emp.name = "송준희";
            emp.age = 41;
            emp.sabeon = "0001";

            //java의 ArrayList<Object>랑 똑같은 거임
            ArrayList b = new ArrayList();
            b.Add(emp);
            b.Add(employee);


            //인덱서
            MyPowerCalc calc 
                = new MyPowerCalc();
            Console.WriteLine("10의 제곱 : " + calc[10]);
            Console.WriteLine("15의 제곱 : " + calc[15]);

            Student sss = new Student("이수성");
            Student sss2= new Student();

        }
    }
}
