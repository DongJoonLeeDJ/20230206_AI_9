#xml.etree.ElementTree->elemTree로 약칭함
import xml.etree.ElementTree as elemTree
import pymysql

#xml 형태로 짤라냄
tree = elemTree.parse('data3.xml')
#data 안에 있는 item들을 모두 찾는다.
data = tree.find('./data').findall('item')

xml_arr = [] #리스트(js의 배열)
xml_dictionary = {} #딕셔너리(js의 객체)
for item in data: #item 태그들을 모두 읽어들임
    xml_dictionary['연번']=item.find('./col[@name="연번"]').text
    try:
        xml_dictionary['서명']=item.find('./col[@name="서명"]').text
    except:
        xml_dictionary['서명']=''
    xml_dictionary['가격'] = item.find('./col[@name="가격"]').text
    xml_arr.append(xml_dictionary)
    xml_dictionary={}#xml_dictionary를 초기화 해야 함
        
conn = pymysql.connect(
    host='localhost',
    user='root',
    password='1234',
    db='myproject',
    charset='utf8')
sql = 'insert into mybook values(%d, "%s", %d)'

cur = conn.cursor() #db연결 후 실행 준비
for item in xml_arr: #with 없이 db실행한 것
    cur.execute(sql %(
                (int)(item['연번'])+4000,
                item['서명'],
                (int)(item['가격'])))
conn.commit() #commit을 딱 한 번 한다.
conn.close()


