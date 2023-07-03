using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PartWorkQualityManager
{
    public class JsonManager : DataManager
    {
        private JsonManager()
        {

        }

        private static JsonManager instance;
        public static JsonManager Instance
        {
            get
            {
                if (instance == null)
                {
                    instance = new JsonManager();
                }
                return instance;
            }
        }

        //파일 추가
        //주어진 경로에 json 파일 추가
        public override void Add(Dictionary<string, object> data)
        {
            QualityManager q = data[TableNames.QUALITYMANAGER] as QualityManager;
            FileImage f = data[TableNames.FILEIMAGE] as FileImage;
            int width = int.Parse(data["width"].ToString());
            int height = int.Parse(data["height"].ToString());
            string fileName = data["filename"].ToString();
            categories = data["categories"] as List<Category>;
            var jInfo = new JObject();
            jInfo.Add(JsonNames.CONTRIBUTER, "미래아이티컨소시엄"); //고정
            jInfo.Add(JsonNames.DATE_CREATED, DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss.ffffff")); //고정
            jInfo.Add(JsonNames.NAME, "부품 품질 검사 영상 데이터(자동차)"); //고정
            jInfo.Add(JsonNames.DESCRIPTION, "부품 품질 검사 영상 데이터(자동차)"); //고정
            jInfo.Add(JsonNames.VERSION, "1.0"); //고정
            jInfo.Add(JsonNames.URL, "miraeit.net/"); //고정
            var jImages = new JArray();
            var jImage = new JObject();

            jImage.Add(JsonNames.LICENSE, 1); //고정
            jImage.Add(JsonNames.FILE_NAME, f.file_name);
            jImage.Add(JsonNames.WIDTH, width);
            jImage.Add(JsonNames.DATE_CAPTURED, f.datetime_captured.ToString("yyyy-MM-dd hh:mm:ss"));
            jImage.Add(JsonNames.ID, 1); //고정
            jImage.Add(JsonNames.HEIGHT, height);
            jImages.Add(jImage);
            var jLicenses = new JArray();
            var jLicense = new JObject();
            jLicense.Add(JsonNames.NAME, "CC BY-NC");//고정
            jLicense.Add(JsonNames.ID, 1);//고정
            jLicense.Add(JsonNames.URL, "http://creativecommons.org/licenses/by-nc-sa/2.0/");//고정
            jLicenses.Add(jLicense);
            var jCategories = new JArray();
            foreach(var item in categories)
            {
                var jCategory = new JObject();
                jCategory.Add(JsonNames.SUPERCATEGORY, "자동차부품품질");
                jCategory.Add(JsonNames.ID, int.Parse(item.id));
                jCategory.Add(JsonNames.NAME, item.name);
                jCategories.Add(jCategory);
            }
            
            var jAnnotations = new JArray();
            var jAnnotation = new JObject();
            jAnnotation.Add(JsonNames.CATEGORY_ID, int.Parse(q.category_id));
            var attributes = new JObject();
            attributes.Add(JsonNames.WORK, q.attribute_work);
            attributes.Add(JsonNames.PART, q.attribute_part);
            attributes.Add(JsonNames.QUALITY, "" );
            attributes[JsonNames.QUALITY] = q.attribute_quality ? "양품" : "불량품";
            jAnnotation.Add(JsonNames.ATTRIBUTES, attributes);
            jAnnotation.Add(JsonNames.ID, 1);//고정
            jAnnotation.Add(JsonNames.IMAGE_ID, 1);//고정
            jAnnotations.Add(jAnnotation);


            var jQuality = new JObject
            {
                { JsonNames.INFO, jInfo },
                { JsonNames.IMAGES, jImages },
                { JsonNames.LICENSES, jLicenses },
                { JsonNames.CATEGORIES, jCategories },
                { JsonNames.ANNOTATIONS, jAnnotations }
            };

            // 저장
            File.WriteAllText($"{fileName}.json", jQuality.ToString());


        }

        //파일 삭제
        //주어진 경로에 json 파일 삭제
        public override void Delete(Dictionary<string, object> data)
        {
        }

        //json 파일 읽는 용도
        public override void Load(Dictionary<string, object> data)
        {
            try
            {
                string strJson = File.ReadAllText(data["file"].ToString());
                JObject jsonObject = JObject.Parse(strJson);
                QualityManager qualityManager = data["data"] as QualityManager;
                qualityManager.file_name = jsonObject[JsonNames.IMAGES][0][JsonNames.FILE_NAME].ToString();
                qualityManager.category_id = jsonObject[JsonNames.ANNOTATIONS][0][JsonNames.CATEGORY_ID].ToString();
                qualityManager.datetime_created = DateTime.Parse(jsonObject[JsonNames.INFO][JsonNames.DATE_CREATED].ToString());
                qualityManager.datetime_captured = DateTime.Parse(jsonObject[JsonNames.IMAGES][0][JsonNames.DATE_CAPTURED].ToString());
                qualityManager.attribute_work = jsonObject[JsonNames.ANNOTATIONS][0][JsonNames.ATTRIBUTES][JsonNames.WORK].ToString();
                qualityManager.attribute_part = jsonObject[JsonNames.ANNOTATIONS][0][JsonNames.ATTRIBUTES][JsonNames.PART].ToString();
                qualityManager.attribute_quality = jsonObject[JsonNames.ANNOTATIONS][0][JsonNames.ATTRIBUTES][JsonNames.QUALITY].ToString() == "불량품" ? false : true;
                qualityManager.date_created = DateTime.Parse(jsonObject[JsonNames.INFO][JsonNames.DATE_CREATED].ToString());


            }
            catch (Exception e)
            {
                printLog( e.Message);
                printLog( e.StackTrace);
            }
        }

        public override void DataManaging(string command, string[] columns, Dictionary<string, object> data)
        {
            switch (command)
            {
                case "add": //json파일을 export
                    Add(data);
                    break;
                case "load": //Json 내용을 화면에 삽입... load를 쓰는 게 나으나... 저거 또 건드릴 생각하니 끔찍하다...
                    Load(data);
                    break;

                default:
                    break;
            }
        }

        //파일 수정
        //주어진 경로에 json 파일 새로쓰기(덮어쓰기)
        public override void Update(Dictionary<string, object> data)
        {
        }

        public override void Insert(Dictionary<string, object> data)
        {
            //  throw new NotImplementedException();
            //  string strCarValueJson = File.ReadAllText(@"./Cars.json");
            //JObject jsonObject = JObject.Parse(data["jsonFile"].ToString());
            //FileImage f = data[TableNames.FILEIMAGE] as FileImage;


            //QualityManager qualityManager = data[TableNames.QUALITYMANAGER] as QualityManager;
            //qualityManager.file_name = jsonObject[JsonNames.IMAGES][0][JsonNames.FILE_NAME].ToString();
            //qualityManager.category_id = jsonObject[JsonNames.ANNOTATIONS][0][JsonNames.CATEGORY_ID].ToString();
            //qualityManager.datetime_created = DateTime.Parse(jsonObject[JsonNames.INFO][JsonNames.DATE_CREATED].ToString());
            //qualityManager.datetime_captured = DateTime.Parse(jsonObject[JsonNames.IMAGES][0][JsonNames.DATE_CAPTURED].ToString());
            //qualityManager.attribute_work = jsonObject[JsonNames.ANNOTATIONS][0][JsonNames.ATTRIBUTES][JsonNames.WORK].ToString();
            //qualityManager.attribute_part = jsonObject[JsonNames.ANNOTATIONS][0][JsonNames.ATTRIBUTES][JsonNames.PART].ToString();
            //qualityManager.attribute_quality = jsonObject[JsonNames.ANNOTATIONS][0][JsonNames.ATTRIBUTES][JsonNames.QUALITY].ToString() == "불량품" ? false : true;
            //qualityManager.date_created = DateTime.Parse(jsonObject[JsonNames.INFO][JsonNames.DATE_CREATED].ToString());

            //f.file_name = qualityManager.file_name;


        }

        /*
         
        public static void LoadJson()
        {
            try
            {
                string strCarValueJson = File.ReadAllText(@"./Cars.json");
                JObject jsonObjectCar = JObject.Parse(strCarValueJson);
                Cars = (from item in jsonObjectCar["cars"]["car"]
                         select new ParkingCar()
                         {
                             ParkingSpot = int.Parse(item["parkingSpot"].ToString()),
                             CarNumber = item["carNumber"].ToString().Replace("{", "").Replace("}", ""),
                             DriverName = item["driverName"].ToString().Replace("{", "").Replace("}", ""),
                             PhoneNumber = item["phoneNumber"].ToString().Replace("{", "").Replace("}", ""),
                             ParkingTime = item["parkingTime"].ToString().Replace("{", "").Replace("}", "") == "" ? DateTime.Now : DateTime.Parse(item["parkingTime"].ToString())
                         }).ToList<ParkingCar>();
            }
            catch (Exception)
            {
                MessageBox.Show("Cars 파일이 누락되었습니다!!!");
                CreateFile(); //파일 새로 만들기
                SaveJson();
                LoadJson();
            }

        }
        public static void SaveJson()
        {
            var jCarArray = new JArray();
            if(Cars.Count > 0)
            {
                foreach (var item in Cars)
                {
                    var jCarobject = new JObject();
                    jCarobject.Add("parkingSpot", item.ParkingSpot);
                    jCarobject.Add("carNumber", item.CarNumber);
                    jCarobject.Add("driverName", item.DriverName);
                    jCarobject.Add("phoneNumber", item.PhoneNumber);
                    jCarobject.Add("parkingTime", item.ParkingTime);
                    jCarArray.Add(jCarobject);
                }
            }
            else
            {
                for(int i = 1; i <= 5; i++)
                {
                    var jCarobject = new JObject();
                    jCarobject.Add("parkingSpot", i);
                    jCarobject.Add("carNumber", "");
                    jCarobject.Add("driverName", "");
                    jCarobject.Add("phoneNumber", "");
                    jCarobject.Add("parkingTime", new DateTime());
                    jCarArray.Add(jCarobject);
                }
            }

            var jCarArrayobect = new JObject();
            jCarArrayobect.Add("car", jCarArray);
            var jCarsobect = new JObject();
            jCarsobect.Add("cars", jCarArrayobect);

            // 저장
            File.WriteAllText(@"./Cars.json", jCarsobect.ToString());
        }
        public static void CreateFile()
        {
            string fileName = @"./Cars.json";
            StreamWriter textWrite = File.CreateText(fileName); //파일이 없으면 자동으로 해당 파일을 생성한다.
            textWrite.Dispose(); //메모리 해제. using 키워드로도 할 수 있으나 파일생성만 할 것이므로 별 차이 없다. 로그 남길 때 using 키워드 이용함.
        }
         
         */
    }
}
