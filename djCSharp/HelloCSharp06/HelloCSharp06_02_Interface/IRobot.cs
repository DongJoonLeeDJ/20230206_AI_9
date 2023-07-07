using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp06_02_Interface
{
    public interface IRobot
    {
        string serialNum { get; set; }
        string name { get; set; }
        void run();//실행
        void eStop();//비상정지
    }
}
