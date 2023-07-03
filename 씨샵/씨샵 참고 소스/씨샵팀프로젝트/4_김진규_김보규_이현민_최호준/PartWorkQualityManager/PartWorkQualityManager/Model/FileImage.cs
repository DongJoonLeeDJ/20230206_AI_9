using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PartWorkQualityManager
{
    public class FileImage: IManagerable
    {
        public string file_name { get; set; }
        public string real_file_path { get; set; }
        public DateTime datetime_captured { get; set; }

        public void updateData(object o)
        {
            FileImage f = o as FileImage;
            file_name= f.file_name;
            real_file_path = f.real_file_path;
            datetime_captured = f.datetime_captured;
        }
    }
}
