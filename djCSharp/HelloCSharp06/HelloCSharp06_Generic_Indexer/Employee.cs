using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp06_Generic_Indexer
{
    public class Employee<T>
    {
        public string name { get; set; }
        public int age { get; set; }
        public T sabeon { get; set; }
    }
}
