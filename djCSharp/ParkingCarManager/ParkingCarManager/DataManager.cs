using System;
using System.Collections.Generic;
using System.Data;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ParkingCarManager
{
    public class DataManager
    {
        public static List<ParkingCar> Cars =
            new List<ParkingCar>();

        static DataManager()
        {
            Load();
        }
        public static void Load()
        {
            try
            {
                DBHelper.selectQuery();//전체 조회
                Cars.Clear(); //list비우기
                foreach(DataRow item in DBHelper.dt.Rows)
                {
                    ParkingCar car = new ParkingCar();
                    car.ParkingSpot = item["parkingSpot"].ToString();
                    car.carNumber = item["carNumber"].ToString();
                    car.driverName = item["driverName"].ToString();
                    car.phoneNumber = item["phoneNumber"].ToString();
                    car.parkingTime = item["parkingTime"].ToString() == "" ?
                        new DateTime() :
                        DateTime.Parse(item["parkingTime"].ToString());
                    Cars.Add(car);

                }
            }
            catch (Exception e)
            {
                System.Windows.Forms.MessageBox.Show(e.Message);
                printLog(e.StackTrace + "load");
            }
        }
        //주차 출차용 Save
        public static void Save(string ps,
            string carNumber, string driverName, 
            string phoneNumber,
            bool isRemove=false)
        {
            try
            {
                DBHelper.updateQuery
                    (ps,carNumber,driverName,phoneNumber,
                    isRemove);
            }
            catch (Exception)
            {

            }
        }
        //주차 공간 추가 삭제용 Save
        public static bool Save(string command, string ps,
            out string contents)
        {
            DBHelper.selectQuery(ps);//해당 공간 유무 체크

            contents = "";
            if (command.Equals("insert"))
                return DBInsert(ps, ref contents);
            else
                return DBDelete(ps, ref contents);

        }
        private static bool DBInsert(string ps, ref string contents)
        {
            if(DBHelper.dt.Rows.Count==0)
            {
                DBHelper.insertQuery(ps);
                contents = $"주차공간 {ps}이/가 추가됨";
                return true;
            }
            else
            {
                contents = $"해당 공간 이미 있음";
                return false;
            }
        }
        private static bool DBDelete(string ps, ref string contents)
        {
            if (DBHelper.dt.Rows.Count != 0)
            {
                DBHelper.deleteQuery(ps);
                contents = $"주차공간 {ps}이/가 삭제됨";
                return true;
            }
            else
            {
                contents = $"해당 공간 없음";
                return false;
            }
        }
        public static void printLog(string contents)
        {
            //ParkingCarManager.exe랑 같은 경로에
            //LogFolder라는 이름의 폴더가 없다면...
            DirectoryInfo di = new DirectoryInfo("LogFolder");
            if(di.Exists == false)
            {
                di.Create();//새로 만든다.
            }
            //@"LogFolder\ParkingHistory.txt"
            //"LogFolder\\ParkingHistory.txt"
            //true : appned 옵션을 true
            //즉 새로운 텍스트가 나오면 덮어쓰지 않고
            //뒤에다가 이어붙인다.
            using (StreamWriter w = new StreamWriter
                (@"LogFolder\ParkingHistory.txt",true)) 
            {
                w.WriteLine(contents);
            }
        }
    }
}
