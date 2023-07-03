using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PartWorkQualityManager
{
    public class PartList: IManagerable
    {
        public string carPart {get;set;}

        public void updateData(object o)
        {
            PartList p = o as PartList;
            carPart = p.carPart ;
        }
    }
}
