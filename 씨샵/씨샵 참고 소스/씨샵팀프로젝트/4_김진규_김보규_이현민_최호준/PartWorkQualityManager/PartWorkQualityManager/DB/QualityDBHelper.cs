using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PartWorkQualityManager
{
    public class QualityDBHelper : DBHelper
    {
        private QualityDBHelper()
        {
            
        }
        private static QualityDBHelper instance;
        public static QualityDBHelper Instance
        {
            get {
                if(instance == null)
                    instance = new QualityDBHelper();
                return instance; 
            }
        }

        public override void executeQuery(string command, string[] columns, Dictionary<string, object> data)
        {
            string sqlcommand = "";
            SqlCommand cmd = new SqlCommand();
            cmd.CommandType = CommandType.Text;
            cmd.CommandTimeout = 60000*5;
            QualityManager q = data["data"] as QualityManager;
            switch (command)
            {
                case "insert":
                    sqlcommand = $"insert into {data["tablename"]} " +
                        $"({columns[(int)Qualities.FILE_NAME]}, {columns[(int)Qualities.CATEGORY_ID]}," +
                        $"{columns[(int)Qualities.DATETIME_CREATED]},{columns[(int)Qualities.DATETIME_CAPTURED]}," +
                        $"{columns[(int)Qualities.ATTRIBUTE_WORK]},{columns[(int)Qualities.ATTRIBUTE_PART]}," +
                        $"{columns[(int)Qualities.ATTRIBUTE_QUALITY]},{columns[(int)Qualities.DATE_CREATED]})" +
                        $" values (@p1,@p2,@p3,@p4,@p5,@p6,@p7,@p8)";
                    cmd.Parameters.AddWithValue("@p1", q.file_name);
                    cmd.Parameters.AddWithValue("@p2", q.category_id);                    
                    cmd.Parameters.AddWithValue("@p3", q.date_created);
                    cmd.Parameters.AddWithValue("@p4", q.datetime_captured);                    
                    cmd.Parameters.AddWithValue("@p5", q.attribute_work);
                    cmd.Parameters.AddWithValue("@p6", q.attribute_part);                    
                    cmd.Parameters.AddWithValue("@p7", q.attribute_quality);
                    cmd.Parameters.AddWithValue("@p8", q.date_created);
                    break;
                case "update": //품질부분은 양불만 고친다. 생성일자등이 있기 때문에 카테고리나 공정, 부품 등록을 잘못했다면 삭제하고 새로 등록을 하여야 한다.(부정확한 데이터 방지)  단, 양불여부는 해당 이슈가 해결되었다면 체크해서 고친다.
                    sqlcommand = $"update {data["tablename"]}  set {columns[(int)Qualities.ATTRIBUTE_QUALITY]}=@p1 where {columns[(int)Qualities.FILE_NAME]}=@p2";
                    cmd.Parameters.AddWithValue("@p1", q.attribute_quality);
                    cmd.Parameters.AddWithValue("@p2", q.file_name);
                    break;
                case "delete":
                    sqlcommand = $"delete from {data["tablename"]} where {columns[(int)Qualities.FILE_NAME]}=@p1";
                    cmd.Parameters.AddWithValue("@p1", q.file_name);
                    break;
                default:
                    break;
            }

            try
            {
                ConnectDB();
                cmd.Connection = conn;
                cmd.CommandText = sqlcommand;
                cmd.ExecuteNonQuery();
            }
            catch (Exception e)
            {
                DBManager.Instance.printLog(e.Message);
                DBManager.Instance.printLog(e.StackTrace);
                throw;
            }
            finally
            {
                conn.Close();
            }

        }

        public override void selectQuery(string pk = null)
        {
            if (pk == null)
            {

                string sqlcommand = "select * from "+ TableNames.QUALITYMANAGER ;
                SqlCommand cmd = new SqlCommand();
                cmd.CommandType = CommandType.Text;
                cmd.CommandText = sqlcommand;

                try
                {
                    ConnectDB();
                    cmd.Connection = conn;
                    da = new SqlDataAdapter(cmd);
                    ds = new DataSet();
                    da.Fill(ds, TableNames.QUALITYMANAGER);
                    dt = ds.Tables[0];
                }
                catch (Exception e)
                {
                    DBManager.Instance.printLog(e.Message);
                    DBManager.Instance.printLog(e.StackTrace);
                }
                finally
                {
                    conn.Close();
                }

            }
            else
            { 
            }

        }
    }
}
