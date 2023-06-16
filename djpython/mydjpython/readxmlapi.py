#https://apis.data.go.kr/1360000/MidFcstInfoService/getMidTa?serviceKey=I35xhBVrKuRe7RbiQpN9NOkt%2B6JQT5Fd0fgCNDuB0dURcjnYRTmTeyrFaNHFDHVY%2FQ4etMclK24pY%2FdEMx2fGQ%3D%3D&numOfRows=10&pageNo=1&regId=11H10701&tmFc=202306160600
from datetime import datetime
import requests
import xml.etree.ElementTree as elemTree
import pymysql
#202306160600
mydate = datetime.today().strftime('%Y%m%d0600')
#print(mydate)
api_url = 'http://apis.data.go.kr/1360000/MidFcstInfoService/getMidTa?serviceKey=I35xhBVrKuRe7RbiQpN9NOkt%2B6JQT5Fd0fgCNDuB0dURcjnYRTmTeyrFaNHFDHVY%2FQ4etMclK24pY%2FdEMx2fGQ%3D%3D&numOfRows=10&pageNo=1&regId=11H10701&tmFc={}'.format(mydate)
#print(api_url)
response = requests.get(api_url,verify=False)
#print(response.text)
MidFcstInfoService = []
xmldatas = elemTree.fromstring(response.text)
weather = xmldatas.find('body').find('items').findall('item')
#print(weather[0].find('regId').text)

conn = pymysql.connect(
     host='localhost',
     user='root',
     password='1234',
     database='myproject',
     charset='utf8'
)


cursor = conn.cursor()

sql = "insert into MidFcstInfoService " \
      "(tmFc, " \
      "taMin3, taMax3," \
      "taMin4, taMax4," \
      "taMin5, taMax5," \
      "taMin6, taMax6," \
      "taMin7, taMax7," \
      "taMin8, taMax8," \
      "taMin9, taMax9," \
      "taMin10, taMax10) values ('{}',{},{},{},{},{},{},{},{},{},{},{},{},{},{},{},{})"\
    .format(mydate,
            weather[0].find('taMin3').text,weather[0].find('taMax3').text,
            weather[0].find('taMin4').text,weather[0].find('taMax4').text,
            weather[0].find('taMin5').text,weather[0].find('taMax5').text,
            weather[0].find('taMin6').text,weather[0].find('taMax6').text,
            weather[0].find('taMin7').text,weather[0].find('taMax7').text,
            weather[0].find('taMin8').text,weather[0].find('taMax8').text,
            weather[0].find('taMin9').text,weather[0].find('taMax9').text,
            weather[0].find('taMin10').text,weather[0].find('taMax10').text,)

#print(sql)

cursor.execute(sql)
conn.commit()
cursor.close()
conn.close()

'''
drop table MidFcstInfoService;

create table MidFcstInfoService
(
rownum int auto_increment primary key,
tmFc char(12) not null,
taMin3 int,
taMax3 int,
taMin4 int,
taMax4 int,
taMin5 int,
taMax5 int,
taMin6 int,
taMax6 int,
taMin7 int,
taMax7 int,
taMin8 int,
taMax8 int,
taMin9 int,
taMax9 int,
taMin10 int,
taMax10 int
);

'''