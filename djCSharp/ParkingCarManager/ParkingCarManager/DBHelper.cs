using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ParkingCarManager
{//https://timeboxstory.tistory.com/10
    //이 링크대로만 하면 연결은 되고, 권한은 없음
    //보안 -> 로그인 -> 서버역할에 다 체크해줘야 다른 데서도 제어가 가능함!

    //db 연결하는 부분
    /*
     public static void ConnectDB()
        {//접속해주는 함수
            try
            {
                string connect = string.Format("Data Source={0};" +
                "Initial Catalog = {1};" +
                "Persist Security Info = True;"+
                "User ID=team;Password=1234",
                "192.168.0.84,1433", "Csharp_Team");
                conn = new SqlConnection(connect);
                conn.Open();
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex);
                Console.WriteLine("connect Fail");
            }
        }
     */
    //conn.ConnectionString = $"Data Source=192.168.0.111,1433; Initial Catalog = MYDB; Persist Security Info = True; User ID=user1; Password=1234";


    public class DBHelper
    {
        private static SqlConnection conn = new SqlConnection();
        public static SqlDataAdapter da;
        public static DataSet ds;
        public static DataTable dt;
        private static void ConnectDB()
        {
            string dataSource = "local";
            string db = "MYDB";
            string security = "SSPI";
            conn.ConnectionString =
                $"Data Source=({dataSource}); initial Catalog={db};" +
                $"integrated Security = {security};" +
                $"Timeout=3";
            conn = new SqlConnection(conn.ConnectionString);
            conn.Open();
        }
        //string ps="-1"(기본값(디폴트값)은 -1)
        //selectQuery(string ps="-1")
        //selectQuery(); ps = -1
        //selectQuery("aaa"); ps = aaa
        public static void selectQuery(string ps="-1")
        {
            try
            {
                ConnectDB();
                SqlCommand cmd = new SqlCommand();
                cmd.Connection = conn;
                if (ps.Equals("-1"))
                    cmd.CommandText = "select * from parkingManager";
                else
                    cmd.CommandText = $"select * from parkingManager " +
                        $"where parkingSpot='{ps}'";
                da = new SqlDataAdapter(cmd);
                ds = new DataSet();
                da.Fill(ds, "ParkingManager");
                dt = ds.Tables[0];
            }
            catch (Exception ex)
            {
                System.Windows.Forms.MessageBox.Show("select 오류");
                DataManager.printLog("select,"+ex.Message+","+ex.StackTrace);
            }
            finally
            {
                conn.Close();
            }
        }
        public static void updateQuery
            (string parkingSpot, string carNumber,
            string driverName, string phoneNumber,
            bool isRemove)
        {
            try
            {
                ConnectDB();
                SqlCommand cmd = new SqlCommand();
                cmd.Connection = conn;
                cmd.CommandType = CommandType.Text;
                string sqlcommand = "";
                if(isRemove) //출차
                {
                    //sql injection 방지 코드 작성해보기
                    sqlcommand = 
                    "update parkingManager set carNumber=''," +
                    "driverName='',phoneNumber=''," +
                    "parkingTime=null where " +
                    "parkingSpot=@p1";
                    cmd.Parameters.AddWithValue("@p1",
                        parkingSpot);
                }
                else //주차
                {//sql injection 방지 코드 작성해보기
                    sqlcommand =
                    "update parkingManager set carNumber=@p1," +
                    "DriverName=@p2,phoneNumber=@p3," +
                    "parkingTime=@p4 where " +
                    "parkingSpot=@p5";
                    cmd.Parameters.AddWithValue("@p1",
                        carNumber);
                    cmd.Parameters.AddWithValue("@p2",
                        driverName);
                    cmd.Parameters.AddWithValue("@p3",
                        phoneNumber);
                    cmd.Parameters.AddWithValue("@p4",
                        DateTime.Now.ToString
                        ("yyyy-MM-dd HH:mm:ss.fff"));
                    cmd.Parameters.AddWithValue("@p5",
                        parkingSpot);
                }
                cmd.CommandText = sqlcommand;
                cmd.ExecuteNonQuery();
            }
            catch (Exception ex)
            {
                System.Windows.Forms.MessageBox.Show("update"+ex.Message);
                DataManager.printLog("update,"+ex.Message+ ","+ex.StackTrace);
            }
            finally
            {
                conn.Close();
            }
        }
        private static void executeQuery(string ps,
            string command)
        {
            string sqlcommand = "";
            if (command.Equals("insert"))
                sqlcommand = "insert into parkingManager(parkingSpot) values (@p1)";
            else
                sqlcommand = "delete from parkingManager where parkingSpot = @p1";

            try
            {
                ConnectDB();
                SqlCommand cmd = new SqlCommand();
                cmd.Connection = conn;
                cmd.CommandType = CommandType.Text;
                cmd.Parameters.AddWithValue("@p1", ps);
                cmd.CommandText=sqlcommand;
                cmd.ExecuteNonQuery();
            }
            catch (Exception ex) 
            {
                System.Windows.Forms.MessageBox.Show(command);
                DataManager.printLog(command+","+ex.Message+ ","+ex.StackTrace);    
            }
            finally
            {
                conn.Close();
            }
        }
        public static void deleteQuery(string ps)
        {
            executeQuery(ps, "delete");
        }
        public static void insertQuery(string ps)
        {
            executeQuery(ps, "insert");
        }

    }
}
