using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp06_Generic_Indexer
{
    public class MyPowerCalc
    {
        public int this[int i]
        {
            get
            {
                return i * i;
            }
        }
    }
}
