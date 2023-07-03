using PartWorkQualityManager;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PartWorkQualityManager
{
    public class DBManager : DataManager
    {
        private DBHelper dbhelper;
        private DataManager datamanager = JsonManager.Instance;

        private DBManager()
        {

        }

        private static DBManager instance;
        public static DBManager Instance
        {
            get
            {
                if (instance == null)
                {
                    instance = new DBManager();
                    instance.Load(); //프로그램 처음 시작 시 
                }
                return instance;
            }
        }


        private void Load_QualityManagers()
        {

            dbhelper = QualityDBHelper.Instance;
            qualityManagers.Clear();
            dbhelper.selectQuery();
            foreach (DataRow item in dbhelper.dt.Rows)
            {
                QualityManager qTemp = new QualityManager();
                qTemp.file_name = item[TableNames.FILE_NAME].ToString();
                qTemp.category_id = item[TableNames.CATEGORY_ID].ToString();
                qTemp.datetime_created = DateTime.Parse(item[TableNames.DATETIME_CREATED].ToString());
                qTemp.datetime_captured = DateTime.Parse(item[TableNames.DATETIME_CAPTURED].ToString());
                qTemp.attribute_work = item[TableNames.ATTRIBUTE_WORK].ToString();
                qTemp.attribute_part = item[TableNames.ATTRIBUTE_PART].ToString();
                qTemp.attribute_quality = bool.Parse(item[TableNames.ATTRIBUTE_QUALITY].ToString());
                qTemp.date_created = DateTime.Parse(item[TableNames.DATE_CREATED].ToString());
                qualityManagers.Add(qTemp);
            }

        }
        private void Load_QualityDisplays()
        {

            //qualityDisplays = (from item in qualityManagers
            //                   select new QualityDisplay()
            //                   {
            //                       file_name = item.file_name,
            //                       category_id = item.category_id,
            //                       category_name = categories.Single(x => x.id == item.category_id).name,
            //                       datetime_created = item.datetime_created,
            //                       datetime_captured = item.datetime_captured,
            //                       attribute_work = item.attribute_work,
            //                       attribute_part = item.attribute_part,
            //                       attribute_quality = item.attribute_quality,
            //                       date_created = item.date_created

            //                   }).ToList<QualityDisplay>();
        }

        private void Load_FileImages()
        {
            dbhelper = FileImageDBHelper.Instance;
            fileImages.Clear();
            dbhelper.selectQuery();
            foreach (DataRow item in dbhelper.dt.Rows)
            {
                FileImage fTemp = new FileImage();
                fTemp.file_name = item[TableNames.FILE_NAME].ToString();
                fTemp.real_file_path = item[TableNames.REAL_FILE_PATH].ToString();
                fTemp.datetime_captured = DateTime.Parse(item[TableNames.DATETIME_CAPTURED].ToString());
                fileImages.Add(fTemp);
            }

        }

        private void Load_Categories()
        {
            dbhelper = CategoryDBHelper.Instance;
            categories.Clear();
            dbhelper.selectQuery();
            foreach (DataRow item in dbhelper.dt.Rows)
            {
                Category cTemp = new Category();
                cTemp.id = item[TableNames.ID].ToString();
                cTemp.name = item[TableNames.NAME].ToString();
                cTemp.supercategory = item[TableNames.SUPERCATEGORY].ToString();
                categories.Add(cTemp);
            }

        }

        private void Load_Parts()
        {
            dbhelper = PartDBHelper.Instance;
            partLists.Clear();
            dbhelper.selectQuery();
            foreach (DataRow item in dbhelper.dt.Rows)
            {
                PartList pTemp = new PartList();
                pTemp.carPart = item[TableNames.CARPART].ToString();
                partLists.Add(pTemp);
            }
        }

        private void Load_Works()
        {
            dbhelper = PartWorkDBHelper.Instance;
            partWorkLists.Clear();
            dbhelper.selectQuery();
            foreach (DataRow item in dbhelper.dt.Rows)
            {
                PartWorkList wTemp = new PartWorkList();
                wTemp.workname = item[TableNames.WORKNAME].ToString();
                partWorkLists.Add(wTemp);
            }
        }


        //프로그램 처음 시작 시 DataManager에 있는 List들에 값 추가
        public override void Load(Dictionary<string, object> data=null)
        {
            Load_QualityManagers();
            Load_FileImages();
            Load_Categories();
            Load_Parts();
            Load_Works();
            Load_QualityDisplays();
           
        }

        //db에 값 수정
        public override void Update(Dictionary<string, object> data)
        {

            try
            {
                IManagerable temp = null;
                switch (data["tablename"].ToString())
                {
                    case TableNames.QUALITYMANAGER:
                        QualityManager q = data["data"] as QualityManager;
                        temp = qualityManagers.Single(x => x.file_name == q.file_name);
                        temp.updateData(q);

                        break;
                    case TableNames.FILEIMAGE:
                        FileImage f = data["data"] as FileImage;
                        temp = fileImages.Single(x => x.file_name == f.file_name);
                        temp.updateData(f);
                        break;
                    case TableNames.CATEGORY:
                        Category c = data["data"] as Category;
                        temp = categories.Single(x => x.id == c.id);
                        temp.updateData(c);
                        break;
                    case TableNames.PARTLIST:
                        PartList oldp = data["oldData"] as PartList;
                        PartList newp = data["data"] as PartList;
                        temp = partLists.Single(x => x.carPart == oldp.carPart);
                        temp.updateData(newp);
                        break;
                    case TableNames.PARTWORKLIST:
                        PartWorkList oldw = data["oldData"] as PartWorkList;
                        PartWorkList neww = data["data"] as PartWorkList;
                        temp = partWorkLists.Single(x => x.workname == oldw.workname);
                        temp.updateData(neww);
                        break;

                    default:
                        break;
                }
            }
            catch (Exception e)
            {
                printLog(e.Message );
                printLog(e.StackTrace);
            }
        }

        ////db에 값 삭제
        public override void Delete(Dictionary<string, object> data)
        {
            try
            {
                switch (data["tablename"].ToString())
                {
                    case TableNames.QUALITYMANAGER:
                        QualityManager q = data["data"] as QualityManager;
                        QualityManager qTemp = qualityManagers.Single(x => x.file_name == q.file_name);
                        qualityManagers.Remove(qTemp);
                        break;
                    case TableNames.FILEIMAGE:
                        FileImage f = data["data"] as FileImage;
                        FileImage fTemp = fileImages.Single(x=>x.file_name==f.file_name);
                        fileImages.Remove(fTemp);
                    break;
                    case TableNames.CATEGORY:
                        Category c = data["data"] as Category;
                        Category cTemp = categories.Single(x=>x.id==c.id);
                        categories.Remove(cTemp);
                        break;
                    case TableNames.PARTLIST:
                        PartList p = data["data"] as PartList;
                        PartList pTemp = partLists.Single(x=>x.carPart==p.carPart);
                        partLists.Remove(pTemp);
                        break;
                    case TableNames.PARTWORKLIST:
                        PartWorkList w = data["data"] as PartWorkList;
                        PartWorkList wTemp = partWorkLists.Single(x=>x.workname==w.workname);
                        partWorkLists.Remove(wTemp);
                        break;

                    default:
                        break;
                }
            }
            catch (Exception e)
            {
                printLog(e.Message);
                printLog(e.StackTrace);
            }

        }


        //실제 db에 값 추가, 파일을 통한 접근 (대량 or 소량)
        //개별 추가랑 분리하기 위하여 별도의 함수 만듦
        public override void Add(Dictionary<string, object> data)
        {
            if (data.ContainsKey("file")) //대량 추가시(폴더 선택시)
            {
                string[] columns;
                switch (data["extension"].ToString())
                {
                    case ".json":
                        data["data"] = new QualityManager();
                        data["tablename"] = TableNames.QUALITYMANAGER;
                        columns = new string[] {TableNames.FILE_NAME, TableNames.CATEGORY_ID,
                        TableNames.DATETIME_CREATED, TableNames.DATETIME_CAPTURED,
                        TableNames.ATTRIBUTE_WORK,TableNames.ATTRIBUTE_PART,
                        TableNames.ATTRIBUTE_QUALITY,TableNames.DATE_CREATED};
                        datamanager.Load(data); //json에서 불러들임, data는 참조변수이므로 그대로 데이터 가져 갈 수 있다. 
                        dbhelper = QualityDBHelper.Instance;
                        dbhelper.executeQuery("insert", columns, data); //json에서 불러들인 것을 excute
                        break;
                    case ".jpg":
                        FileImage f = new FileImage();
                        f.file_name = data["fileName"].ToString();
                        f.real_file_path = data["file"].ToString();
                        //datetime_captured는 json에서 받아와야 한다. 파일 자체 정보랑 이 정보가 일치하지 않는 경우들이 있다.
                        //그냥 now나 파일에 있는 정보라도 가져올 순 있다.
                        //그냥 나중에 dbms에서 update join을 돌리자.
                        data.Add("data", f);
                        data.Add("tablename", TableNames.FILEIMAGE);
                        columns = new string[] { TableNames.FILE_NAME, TableNames.REAL_FILE_PATH };
                        dbhelper = FileImageDBHelper.Instance;
                        dbhelper.executeQuery("insert", columns, data); //파일이름정보를 바로 execute
                        break;

                    default:
                        break;
                }
            }
            //이 조건문으 이제 의미 없음
            //원랜 json을 추가하고 나서 그 뒤에 부가적으로 이미지 넣는 줄 암
            //근데 살펴보니 이미지를 먼저 넣고 그거에 대한 정보를 넣거나
            //혹은 넣지 않거나를 결정함
            //불량 발생시 혹은 애매할 때 일단 사진부터 찍고
            //그 뒤에 품질 관리에 있어서 필요한 정보만 등록을 하는 것이다.
            //else //폴더 선택이 아닌 경우
            //{

            //}
        }

        public override void Insert(Dictionary<string, object> data)
        {
            //throw new NotImplementedException();
            switch (data["tablename"].ToString())
            {
                case TableNames.QUALITYMANAGER:
                    QualityManager q = data["data"] as QualityManager;
                    qualityManagers.Add(q);

                    break;
                case TableNames.FILEIMAGE:
                    FileImage f = data["data"] as FileImage;
                    fileImages.Add(f);
                    break;
                case TableNames.CATEGORY:
                    Category c = data["data"] as Category;
                    categories.Add(c);
                    break;
                case TableNames.PARTLIST:
                    PartList p = data["data"] as PartList;
                    partLists.Add(p);
                    break;
                case TableNames.PARTWORKLIST:
                    PartWorkList w = data["data"] as PartWorkList;
                    partWorkLists.Add(w);
                    break;

                default:
                    break;
            }
        }


        //데이터 하나에 대한 추가/수정/삭제
        public override void DataManaging(string command, string[] columns, Dictionary<string, object> data)
        {
            switch (data["tablename"].ToString())
            {
                case TableNames.QUALITYMANAGER:
                    dbhelper = QualityDBHelper.Instance;
                    break;
                case TableNames.FILEIMAGE:
                    dbhelper = FileImageDBHelper.Instance;
                    break;
                case TableNames.CATEGORY:
                    dbhelper = CategoryDBHelper.Instance;
                    break;
                case TableNames.PARTLIST:
                    dbhelper = PartDBHelper.Instance;
                    break;
                case TableNames.PARTWORKLIST:
                    dbhelper = PartWorkDBHelper.Instance;
                    break;

                default:
                    break;
            }
            try
            {
                dbhelper.executeQuery(command, columns, data);
            }
            catch (Exception)
            {
                printLog(  "쿼리 실패"  );
                return;
            }

            switch (command)
            {
                case "insert":
                    Insert(data);
                    break;
                case "update":
                    Update(data);
                    break;
                case "delete":
                    Delete(data);
                    break;
                default:
                    break;
            }
        }
    }
}
