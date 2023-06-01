import json
import pymysql
#encoding= 적어주는 이유
#특정 메소드의 어떤 파라메터에 값을 넣을지 지정해주는 것
#별도로 f.close 안 해도 자동으로 됨
with open(encoding='utf-8',file='data2.json') as f:
    json_object = json.load(f) #json 파일 읽어옴
    #json_object 변수 선언 후 파일 내용을 넣기
print(json_object)
conn = pymysql.connect(
    host='localhost',
    user='root',
    password='1234',
    db='myproject',
    charset='utf8')
sql = 'insert into mybook values(%d, "%s", %d)'
json_arr = json_object['data']#속성이 'data'인 것만 가져옴
cur = conn.cursor() #db연결 후 실행 준비
for item in json_arr: #with 없이 db실행한 것
    cur.execute(sql %(
                (int)(item['연번'])+3000,
                item['서명'],
                (int)(item['가격'])))
conn.commit() #commit을 딱 한 번 한 다.
conn.close()