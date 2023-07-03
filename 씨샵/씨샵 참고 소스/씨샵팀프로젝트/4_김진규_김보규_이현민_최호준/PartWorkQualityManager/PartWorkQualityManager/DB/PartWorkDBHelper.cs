using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PartWorkQualityManager
{
    public class PartWorkDBHelper : DBHelper
    {
        private PartWorkDBHelper()       {         }
        private static PartWorkDBHelper instance;
        public static PartWorkDBHelper Instance
        {
            get
            {
                if (instance == null)
                    instance = new PartWorkDBHelper();
                return instance;
            }
        }
        public override void selectQuery(string pk = null)
        {
            if (pk == null)
            {

                string sqlcommand = "select * from " + TableNames.PARTWORKLIST;
                SqlCommand cmd = new SqlCommand();
                cmd.CommandType = CommandType.Text;
                cmd.CommandText = sqlcommand;

                try
                {
                    ConnectDB();
                    cmd.Connection = conn;
                    da = new SqlDataAdapter(cmd);
                    ds = new DataSet();
                    da.Fill(ds, TableNames.PARTWORKLIST);
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

        public override void executeQuery(string command, string[] columns, Dictionary<string, object> data)
        {
            string sqlcommand = "";
            SqlCommand cmd = new SqlCommand();
            cmd.CommandType = CommandType.Text;
            PartWorkList temp = data["data"] as PartWorkList;
            cmd.CommandTimeout = 60000*5;
            PartWorkList old = data["oldData"] as PartWorkList; //업데이트용
            switch (command)
            {
                case "insert":
                    sqlcommand = $"insert into {data["tablename"]} " +
                        $"({columns[(int)Works.WORKNAME]})" +
                        $" values (@p1)";
                    cmd.Parameters.AddWithValue("@p1", temp.workname);
                    break;
                case "update"://기존값을 따로 저장해두어야 할 듯 하다.
                    sqlcommand = $"update {data["tablename"]} set " +
                        $"{columns[(int)Works.WORKNAME]} = @p1 where " +
                        $" {columns[(int)Works.WORKNAME]}=@p2";
                    cmd.Parameters.AddWithValue("@p1", temp.workname);
                    cmd.Parameters.AddWithValue("@p2", old.workname);

                    break;
                case "delete":
                    sqlcommand = $"delete from {data["tablename"]} where {columns[(int)Works.WORKNAME]}=@p1";
                    cmd.Parameters.AddWithValue("@p1", temp.workname);
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
    }
}
