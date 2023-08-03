# 주석
"""
여러줄 짜리 주석
혹은
멀티라인 문자열
"""
'''
여러 줄 짜리 주석도 되고
여러 줄 짜리 문자열도 됨
'''
print("-"*50) #-가 50개
print(2**5) # 32
s = """
안녕하세요
이동준입니다.
"""
print(s)

#print("안녕"+3)
print("안녕"+str(3))
#print("123"+123)
print(int("123")+123)

print("안녕"+"하세요")

print('안녕 "이동준"\n반가워')

mylist = []
#mylist[0] = 100

#js의 push
mylist.append(100)
mylist = mylist + [10,20]

print(mylist)
print(mylist[-1])
print(mylist[0:2])
print(mylist[-2:])

mylist.insert(1,50)
print(mylist)

a = mylist.pop()
b = mylist.pop(0)
#100 50 10 20
print(a) # 20
print(b) # 100
print(mylist) #[50,10]
del mylist[0]
print(mylist)
print(len(mylist))

mytuple = (1,2,3)
#mytuple[0]=100 #TypeError: 'tuple' object does not support item assignment
#mytuple = (1,2,3)+(10)
mytuple = (1,2,3)+(10,)
print(mytuple)

# key : 숫자와 문자만 가능
# value : 형태 제한 없음
djlee = {
    'name' : '이동준',
    34 : '그의 나이',
    '태어난 해' : 1989,
    '언어' : ['C','C#','java','python'],
    'phone' : {
        'name' : 's10 note',
        'os' : 'android',
        'brand' : 'samsung'
    }
}

print(djlee)
print(djlee[34])
print(djlee['name'])
print(djlee['태어난 해'])
print(djlee['언어'])
print(djlee['언어'][0])

djlee['외국어'] = '영어'
print(djlee)
djlee['외국어'] = ['한국어','한본어','영어']
print(djlee)
djlee.clear()
print(djlee)

ldj = '이동준'
if ldj=='이동준':
    print('hey dj')

# input() = 입력
print("나이 적어주세요")
age = int(input())
print("내가 태어난 해")
print(2023-age)

sum = 0
for item in range(1,101):
    sum += item
print("총합 = " + str(sum))
print("총합 = %d" % sum)
#개수가 1개 이상이면 괄호로 감쌀 것
print("%d부터 %d까지의 총합 = %d" % (1,100,sum))
print("{}~{}의 합 {}".format(1,100,sum))
print("{0}~{1}의 합 {2}".format(1,100,sum))
# ` 그레이브키랑 $ 쓴 것
# c#에서 $ 활용한 것
print(f"{1}~{100}까지의 합 : {sum}")

#튜플 여러 개를 출력하는 방법
simbols = [ ('파이썬','비단뱀') , ('리눅스','펭귄') , ('java','커피')]
for k,v in simbols:
    print(k,v)
simbols = [('파이썬', '비단뱀','py'), ('리눅스', '펭귄','lx'), ('java', '커피','class')]
for a,b,c in simbols:
    print(a,b,c)

djlee = {
    'born' : '890430',
    'gen' : 'man',
    'name' : 'ldj'
}

for keys in djlee.keys():
    print(keys)

for v in djlee.values():
    print(v)

for item in djlee.items():
    print(item)
for k,v in djlee.items():
    print(k,v)