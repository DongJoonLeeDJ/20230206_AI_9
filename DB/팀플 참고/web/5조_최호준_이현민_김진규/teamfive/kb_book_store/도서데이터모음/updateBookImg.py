import pymysql
import json
import urllib.request
import time
#DB 연결 세팅
conn = pymysql.connect(host='localhost',
                       user='kb_bookstore_admin',
                       password='kbadmin',
                       db='kb_book_store',
                       charset='utf8')

cur = conn.cursor()
sql = "SELECT * FROM book"

cur.execute(sql)
#테이블에 있는 값들을 모두 읽어 옴
result = cur.fetchall()

#naver 도서 api 키
client_id = "R9RvEToCf5NQ0BY1B4mf"
client_secret = "aFVVBFV1J0"

for item in result:
    isbn = item[1]
    encText = urllib.parse.quote(isbn) #isbn을 기준으로 도서 검색
    url = 'https://openapi.naver.com/v1/search/book_adv.json?d_isbn=' + encText
    request = urllib.request.Request(url)
    request.add_header("X-Naver-Client-Id", client_id)
    request.add_header("X-Naver-Client-Secret", client_secret)
    response = urllib.request.urlopen(request)
    rescode = response.getcode()
    if(rescode==200): #요청 성공시
        response_body=json.load(response)
        try: #이미지가 없거나 isbn이 없는 경우들에 대해서는 무시
            cur.execute("update book set bookImg='{}' where bookisbn='{}'".
                        format(response_body['items'][0]['image'],isbn))
            print("update book set bookImg='{}' where bookisbn='{}'".
                        format(response_body['items'][0]['image'],isbn)) #요청을 너무 빠르게 할 경우 오류 나므로, 천천히 요청하기 위한 대책 중 하나(1/2)(쿼리문 일일히 프린트하기)
            conn.commit() #DB에 적용
            time.sleep(0.2) #0.2초간 딜레이를 준다. 요청을 천천히 하기 위한 대책 중 하나(2/2)
            #print(response_body['items'][0]['image'])
        except:
            pass
    else:
        print("Error Code:" + rescode)

