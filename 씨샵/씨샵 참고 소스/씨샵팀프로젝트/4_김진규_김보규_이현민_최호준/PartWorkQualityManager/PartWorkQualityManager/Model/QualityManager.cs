using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PartWorkQualityManager
{
    public class QualityManager : IManagerable
    {
        public string file_name { get; set; }
        public string category_id { get; set; }
        public DateTime datetime_created { get; set; }
        public DateTime datetime_captured { get; set; }
        public string attribute_work { get; set; }
        public string attribute_part { get; set; }
        public bool attribute_quality { get; set; }
        public DateTime date_created { get; set; }

        public void updateData(object o)
        {
            QualityManager q = o as QualityManager;
            file_name = q.file_name;
            category_id = q.category_id;
            datetime_created = q.datetime_created;
            datetime_captured = q.datetime_captured;
            attribute_work = q.attribute_work;
            attribute_part = q.attribute_part;
            attribute_quality = q.attribute_quality;
            date_created = q.date_created;
        }
    }
}
