using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PartWorkQualityManager
{
    public class FileImageDBHelper : DBHelper
    {

        private FileImageDBHelper()
        {

        }
        private static FileImageDBHelper instance;
        public static FileImageDBHelper Instance
        {
            get
            {
                if (instance == null)
                    instance = new FileImageDBHelper();
                return instance;
            }
        }

        public override void selectQuery(string pk = null)
        {
            if (pk == null)
            {

                string sqlcommand = "select * from " + TableNames.FILEIMAGE;
                SqlCommand cmd = new SqlCommand();
                cmd.CommandType = CommandType.Text;
                cmd.CommandText = sqlcommand;

                try
                {
                    ConnectDB();
                    cmd.Connection = conn;
                    da = new SqlDataAdapter(cmd);
                    ds = new DataSet();
                    da.Fill(ds, TableNames.FILEIMAGE);
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
            cmd.CommandTimeout = 60000*5;
            FileImage fileImage = data["data"] as FileImage;
            switch (command)
            {
                case "insert":
                    sqlcommand = $"insert into {data["tablename"]} ({columns[(int)FileImages.FILENAME]}, " +
                        $"{columns[(int)FileImages.REAL_FILE_NAME]}, {columns[(int)FileImages.DATETIME_CAPTURED]}) values (@p1,@p2,@p3)";
                    cmd.Parameters.AddWithValue("@p1", fileImage.file_name);
                    cmd.Parameters.AddWithValue("@p2", fileImage.real_file_path);
                    cmd.Parameters.AddWithValue("@p3", DateTime.Now);
                    break;
                case "update":
                    //이미지 부분만 따로 수정하지 않는다. 왜냐면 합불여부만 수정하도록 하기 떄문이다.
                    //이미지 수정이나 다른 거 수정 필요하면 그 데이터는 삭제하고 다시 올려야 한다.
                    //그래야 정확한 품질 관리가 된다.(데이터 오류 최소화)
                    //굳이 수정한다면 파일명을 기준으로 시간이나 경로를 수정할 수 있으나... 이러면 데이터가 더 꼬인다.
                    //sqlcommand = $"update {data["tablename"]} set {columns[(int)FileImages.REAL_FILE_NAME]} = @p1, {columns[(int)FileImages.DATETIME_CAPTURED]}=@p2 where " +
                    //    $"{columns[(int)FileImages.FILENAME]}=@p3";
                    //cmd.Parameters.AddWithValue("@p1", fileImage.real_file_path);
                    //cmd.Parameters.AddWithValue("@p2", fileImage.datetime_captured);
                    //cmd.Parameters.AddWithValue("@p3", fileImage.file_name);
                    break;
                case "delete":
                    sqlcommand = $"delete from {data["tablename"]} where {columns[(int)FileImages.FILENAME]}=@p1";
                    cmd.Parameters.AddWithValue("@p1", fileImage.file_name);
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
