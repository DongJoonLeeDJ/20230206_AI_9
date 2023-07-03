using PartWorkQualityManager; 
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PartWorkQualityManager
{

    //json파일과 db 파일 2개를 다룬다.
    public abstract class DataManager
    {
        public List<QualityManager> qualityManagers = new List<QualityManager>();
        public List<Category> categories = new List<Category>();
        public List<FileImage> fileImages = new List<FileImage>();
        public List<PartList> partLists = new List<PartList>();
        public List<PartWorkList> partWorkLists = new List<PartWorkList>();

        //프로그램 처음 켤 때 db에서 읽어옴
        public abstract void Load(Dictionary<string, object> data=null);

        //디렉토리 이용해서 대량 추가
        //(참고 : 대량 추가시에는 Load를 호출해야 함. Add 안에서 호출하진 않음. 기능 분리)
        //하나씩 수동 추가 => db랑 json에 추가

        public abstract void DataManaging(string command, string[] columns, Dictionary<string, object> data);


        public abstract void Add(Dictionary<string, object> data);

        //하나씩 수동 수정 => db랑 json 값 수정
        public abstract void Update(Dictionary<string, object> data);

        //하나씩 수동 삭제 => db랑 json 삭제
        public abstract void Delete(Dictionary<string, object> data);

        public abstract void Insert(Dictionary<string, object> data);


        //파일에 내용 적는 것
        public void printLog(string contents)
        {
            //ParkingHistory 폴더
            DirectoryInfo di = new DirectoryInfo("ParkingHistory");
            if (di.Exists == false) //해당 폴더 없다면
                di.Create(); //폴더 생성함

            //ParkingHistory 폴더 안에 ParkingHistory.txt에 글을 쓸 것
            //끝에 붙은 true 의미
            //append를 한다. 즉 새로운 내용을 뒤에 추가한다는 뜻
            using (StreamWriter w = new StreamWriter
                ("ParkingHistory\\ParkingHistory.txt", true))
            {
                w.WriteLine(DateTime.Now.ToString("[yyyy-MM-dd HH:mm:ss.fff]")+contents);
            }
        }

        public void setDataGridView(DataGridView gridView, List<QualityManager> list)
        {
            gridView.DataSource = null;
            if (list.Count > 0)
            {
                gridView.DataSource = list;
            }
        }

        public void setDataGridView(DataGridView gridView, List<FileImage> list)
        {
            gridView.DataSource = null;
            if (list.Count > 0)
            {
                gridView.DataSource = list;
            }
        }


    }
}
