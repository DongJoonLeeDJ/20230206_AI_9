using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace HelloCSharp07
{
    public class DataManager
    {
        //클래스 변수
        //인스턴스 변수가 아니므로 이 List들은 공유된다.
        public static List<Book> Books = new List<Book>();
        public static List<User> Users = new List<User>();

        //XML방식을 통해서 데이터 관리할 것
        //XML 태그 이름을 미리 적어놓을 것이다
        //이유 : 오타 방지

        //상수는 대문자로 적는 것이 관례
        const string ISBN = "isbn";
        const string NAME = "name";//책이름, 유저이름
        const string PUBLISHER = "publisher";
        const string PAGE = "page";
        const string USERID = "userid";
        const string USERNAME = "username";
        const string ISBORROWED = "isborrowed";
        const string BORROWEDAT = "borrowedAt";
        const string ID = "id";

        //정적 생성자
        //맨 처음 딱 한 번만 호출됨(아래 둘 중 하나일 경우에 생성됨)
        //1. 해당 클래스에 있는 인스턴스에 접근할 때
        //2. 해당 클래스로 접근할 때(ex. DataManager.Books)
        //책 6단원 중에 있음
        static DataManager()
        {
            Load();
        }

        public static void Load()
        {
            try
            {
                //@의 용도
                //string test = @"\안녕";
                //test = "\\안녕";
                //ReadAllText : 파일에 있는 글자들을 전부 읽어들인 것
                string booksOutput = File.ReadAllText("./Books.xml");
                XElement bx = XElement.Parse(booksOutput);
                Books.Clear(); 
                foreach (var item in bx.Descendants("book"))
                {
                    Book book = new Book();
                    book.isbn = item.Element(ISBN).Value; 
                    book.name = item.Element(NAME).Value;
                    book.publisher = item.Element(PUBLISHER).Value;
                    book.page = int.Parse(item.Element(PAGE).Value);
                    book.BorrowedAt
                        = DateTime.Parse
                        (item.Element(BORROWEDAT).Value);
                    book.isBorrowed = 
                        item.Element(ISBORROWED).Value != "0" ? true : false;
                    book.userId = item.Element(USERID).Value;
                    book.userName = item.Element(USERNAME).Value;
                    Books.Add(book);
                }

                string usersOutput = File.ReadAllText("./Users.xml");
                XElement ux = XElement.Parse(usersOutput);
                //Clear 필요없음
                //바로 대입하므로 필요없다.
                Users = (from item in ux.Descendants("user")
                         select new User()
                  {
                             id= item.Element(ID).Value,
                             name = item.Element(NAME).Value
                  }).ToList<User>();

            }
            catch (Exception) //Save가 제대로 안 되서
            {                            //Load 실패하면 무한호출
                Save();              //StackOverFlow 날 수 있음
                Load();
            }
        }

        public static void Save() 
        {
            string booksOutput = "";
            booksOutput += "<books>\n";
            foreach(var item in Books)
            {
                booksOutput += " <book>\n";
                booksOutput += $"   <{ISBN}>{item.isbn}</{ISBN}>\n";
                booksOutput += $"   <{NAME}>{item.name}</{NAME}>\n";
                booksOutput += $"   <{PUBLISHER}>{item.publisher}</{PUBLISHER}>\n";
                booksOutput += $"   <{PAGE}>{item.page}</{PAGE}>\n";
                booksOutput += $"   <{BORROWEDAT}>{item.BorrowedAt}</{BORROWEDAT}>\n";
                booksOutput += $"   <{ISBORROWED}>"+(item.isBorrowed?1:0)+$"</{ISBORROWED}>\n";
                booksOutput += $"   <{USERID}>"+(item.userId)+$"</{USERID}>\n";
                booksOutput += $"   <{USERNAME}>{item.userName}</{USERNAME}>\n";
                booksOutput += " </book>\n";
            }
            booksOutput += "</books>";
            //기존 내용 덮어쓰고 xml 파일에 새로운 내용을 넣음
            File.WriteAllText("./Books.xml", booksOutput);

            string usersOutput = "";
            usersOutput += "<users>\n";
            foreach(var item in Users)
            {
                usersOutput += " <user>\n";
                usersOutput += $"    <{ID}>{item.id}</{ID}>";
                usersOutput += $"    <{NAME}>{item.name}</{NAME}>";
                usersOutput += " </user>\n";
            }
            usersOutput += "</users>\n";
            File.WriteAllText("./Users.xml", usersOutput);
        }
    }
}
