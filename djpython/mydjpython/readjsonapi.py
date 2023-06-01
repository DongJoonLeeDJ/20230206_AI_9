import json
import pymysql
import urllib.request #웹쪽 데이터 가져오기
url = 'https://api.odcloud.kr/api/15060954/v1/uddi:26847c54-1f80-4c3d-bd5d-c0402b637041?page=3&perPage=99&serviceKey=I35xhBVrKuRe7RbiQpN9NOkt%2B6JQT5Fd0fgCNDuB0dURcjnYRTmTeyrFaNHFDHVY%2FQ4etMclK24pY%2FdEMx2fGQ%3D%3D'
response = urllib.request.urlopen(url)
response_message = response.read().decode('utf8')

data = json.loads(response_message)#String->json으로 변환
json_arr = data['data']

conn = pymysql.connect(
    host='localhost',
    user='root',
    password='1234',
    db='myproject',
    charset='utf8')
sql = 'insert into mybook values(%d, "%s", %d)'

cur = conn.cursor() #db연결 후 실행 준비
for item in json_arr: #with 없이 db실행한 것
    cur.execute(sql %(
                (int)(item['연번'])+5000,
                item['서명'],
                (int)(item['가격'])))
conn.commit() #commit을 딱 한 번 한다.
conn.close()