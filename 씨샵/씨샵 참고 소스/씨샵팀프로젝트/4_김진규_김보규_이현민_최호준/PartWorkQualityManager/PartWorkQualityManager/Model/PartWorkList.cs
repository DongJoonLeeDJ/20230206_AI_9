using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PartWorkQualityManager
{
    public class PartWorkList : IManagerable
    {
        public string workname { get; set; }

        public void updateData(object o)
        {
            PartWorkList w = o as PartWorkList;
            workname = w.workname;
        }
    }
}
