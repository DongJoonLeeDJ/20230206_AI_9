using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PartWorkQualityManager
{
    public enum FileImages
    {
        FILENAME, REAL_FILE_NAME, DATETIME_CAPTURED
    }
    public enum Categories
    {
        ID, NAME, SUPERCATEGORY
    }
    public enum Qualities
    {
        FILE_NAME, CATEGORY_ID, DATETIME_CREATED, DATETIME_CAPTURED, ATTRIBUTE_WORK, ATTRIBUTE_PART, ATTRIBUTE_QUALITY, DATE_CREATED
    }
    public enum Parts
    {
        CARPART
    }
    public enum Works
    {
        WORKNAME
    }
}
