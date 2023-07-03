using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PartWorkQualityManager
{
    //QualityManager, FileImage, Category, PartList, PartWorkList를 다룬다.
    public abstract class DBHelper
    {
        protected SqlConnection conn;
        protected SqlDataAdapter da = new SqlDataAdapter();
        protected DataSet ds = new DataSet();
        public DataTable dt = new DataTable();

        //DB 연결하는 부분
        public void ConnectDB()
        {
            conn = new SqlConnection();
            conn.ConnectionString =
                string.Format("Data Source=({0}); initial Catalog = {1}; integrated Security = {2};" +
                "Timeout=300",
                "local", "FactoryBigDataDB", "SSPI");
            conn.Open();
        }

        public abstract void selectQuery(string pk=null);
        public abstract void executeQuery(string command, string[] columns, Dictionary<string, object> data); 
    }
}
