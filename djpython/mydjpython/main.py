# 이건 주석(한 줄)
'''
여러줄
주석
큰따옴표로 대신 써도 됨
'''
"""
이 것도 여러 줄 주석임 ㅇㅇ
그와 동시에 멀티라인 String 값이 되기도
합니다.
"""
a = 10
a = "aaa" #정수도 들어가고 문자열도 들어감

if a=="aaa":
    print("aaa입니다.")
elif a==10:
    print('a는 10')
    print('여러 줄 작성 가능')
else:
    print("이도 저도 아님")
print('---')
i = 0
a = 10
while i<a:
    print(i)
    i+=1 #i++이 없다
print('---')
for item in range(1,11,1):
    print(item)#1부터10까지 출력

mydata = []
mydata.append(10)#js의 push와 동일
mydata.append(20)
mydata.insert(1,15) #두번째에 15 삽입

print('---')
for item in mydata:
    print(item)







