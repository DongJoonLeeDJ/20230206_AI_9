using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp06_Generic_Indexer
{
    public class Student
    {
        public string name { get; set; }
        public int age { get; set; }
        public Student() { }

        public Student(string name)
        {
            this.name = name;
        }

        /*
         public Student(){}
         
         */
    }
}
