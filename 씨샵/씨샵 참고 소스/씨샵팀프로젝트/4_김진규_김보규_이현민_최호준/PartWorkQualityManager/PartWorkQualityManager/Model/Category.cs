using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PartWorkQualityManager
{
    public class Category : IManagerable
    {
        public string id { get; set; }
        public string name { get; set; }
        public string supercategory { get; set; }

        public void updateData(object o)
        {
            Category c = o as Category;
            id = c.id;
            name = c.name;
            supercategory = c.supercategory;
        }
    }
}
