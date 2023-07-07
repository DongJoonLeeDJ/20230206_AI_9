using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp06_02_Interface
{
    public interface IPet
    {
        string alias { get; set; }
        void charm();//애교부리기
        void sayHello();//반겨주기
    }
}
