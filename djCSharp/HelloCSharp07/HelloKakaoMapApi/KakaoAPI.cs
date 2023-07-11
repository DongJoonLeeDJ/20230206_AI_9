using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using System.Web.Script.Serialization;

namespace HelloKakaoMapApi
{
    public class KakaoAPI
    {
        public static List<Locale> Search(string text)
        {
            List<Locale> list = new List<Locale>();

            string url = "https://dapi.kakao.com/v2/local/search/keyword.json";
            string query = $"{url}?query={text}";
            string restAPIKey = "1666a10901745bf107d96d73d18d33e9";
            string Header = $"KakaoAK {restAPIKey}";
            WebRequest request = WebRequest.Create(query);
            request.Headers.Add("Authorization", Header);

            //응답받기
            WebResponse response = request.GetResponse();
            Stream stream = response.GetResponseStream();
            StreamReader reader = new StreamReader(stream,Encoding.UTF8);
            string json = reader.ReadToEnd();

            JavaScriptSerializer js = new JavaScriptSerializer();

            //dynamic이 js의 var, let이랑 똑같은 것
            dynamic dob = js.Deserialize<dynamic>(json);
            dynamic docs = dob["documents"];
            object[] buf = docs;
            int length = buf.Length;
            for(int i =0;i<length;i++)
            {
                string lname = docs[i]["place_name"];
                double x = double.Parse(docs[i]["x"]);
                double y = double.Parse(docs[i]["y"]);
                list.Add(new Locale(lname, y, x));
            }

            return list;
        }
    }
}
