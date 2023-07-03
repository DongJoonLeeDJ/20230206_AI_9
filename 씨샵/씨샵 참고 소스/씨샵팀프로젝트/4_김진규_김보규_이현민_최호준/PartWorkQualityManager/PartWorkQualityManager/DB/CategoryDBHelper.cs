using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PartWorkQualityManager
{
    public class CategoryDBHelper : DBHelper
    {

        private CategoryDBHelper()
        {

        }
        private static CategoryDBHelper instance;
        public static CategoryDBHelper Instance
        {
            get
            {
                if (instance == null)
                    instance = new CategoryDBHelper();
                return instance;
            }
        }

        public override void selectQuery(string pk = null)
        {
            if (pk == null)
            {

                string sqlcommand = "select * from " 
                    + TableNames.CATEGORY;
                SqlCommand cmd = new SqlCommand();
                cmd.CommandType = CommandType.Text;
                cmd.CommandText = sqlcommand;

                try
                {
                    ConnectDB();
                    cmd.Connection = conn;
                    da = new SqlDataAdapter(cmd);
                    ds = new DataSet();
                    da.Fill(ds, TableNames.CATEGORY);
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
            cmd.CommandTimeout = 60000*5;
            cmd.CommandType = CommandType.Text;
            Category temp = data["data"] as Category;
            switch (command)
            {
                case "insert":
                    sqlcommand = $"insert into {data["tablename"]} " +
                        $"({columns[(int)Categories.ID]}, {columns[(int)Categories.NAME]}," +
                        $"{columns[(int)Categories.SUPERCATEGORY]})" +
                        $" values (@p1,@p2,@p3)";
                    cmd.Parameters.AddWithValue("@p1", temp.id);
                    cmd.Parameters.AddWithValue("@p2", temp.name);
                    cmd.Parameters.AddWithValue("@p3", temp.supercategory);
                    break;
                case "update":
                    sqlcommand = $"update {data["tablename"]} set " +
                        $"{columns[(int)Categories.NAME]} = @p1," +
                        $"{columns[(int)Categories.SUPERCATEGORY]} = @p2 where " +
                        $" {columns[(int)Categories.ID]}=@p3";
                    cmd.Parameters.AddWithValue("@p1", temp.name);
                    cmd.Parameters.AddWithValue("@p2", temp.supercategory);
                    cmd.Parameters.AddWithValue("@p3", temp.id);
                    break;
                case "delete":
                    sqlcommand = $"delete from {data["tablename"]} where {columns[(int)Categories.ID]}=@p1";
                    cmd.Parameters.AddWithValue("@p1", temp.id);
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
