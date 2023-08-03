def calcCircle(r, PI):
    print(f"원넓이 : {r*r*PI}")
    print(f"원둘레 : {2*r*PI}")

def aTobSum(a,b):
    sum = 0
    for item in range(a,b+1):
        sum += item
    return sum

calcCircle(10,3.14)
print(aTobSum(1,100))
a = aTobSum(1,100)
print(a)
b = aTobSum(b=100,a=1)#매개변수 수동 지정 가능

#enumerate : 리스트나 튜플 혹은 문자열의
#인덱스와 해당 값을 반환

numberlist = [100,200,300,400,500]
for idx,val in enumerate(numberlist):
    print(f"numlist[{idx}]={val}")
sentense = "이수성,김신혁"
for idx,val in enumerate(sentense):
    print(f"sentense[{idx}]={val}")

#find = 특정 문자열의 시작 인덱스 찾기
#김신혁이라는 글자가 [4]부터 시작함
print(sentense.find("김신혁"))
print(sentense.find("이동준")) #-1

#filter
def is_odd(n):
    return n%2==1
nums = range(1,11)
#int("123"), str(123)
oddlist = list(filter(is_odd, nums))
print(oddlist)
#lambda : 익명 함수
# x : 매개변수
check_odd = lambda a : a%2==1
oddlist1 = list(filter(check_odd,nums))
oddlist2 = list(filter(lambda x:x%2==1,nums))
print(oddlist1)
print(oddlist2)

#filter: 걸러내서 원하는 것만 갖는 것
#map : 각 요소의 값들로 함수를 호출함
mymap = list(map(lambda x: x**3, nums))
print(mymap)

class Student:
    #__init__ : 생성자, 이름을 이렇게 지어야 함
    #self는 무조건 매개변수의 첫번째에 꼭 들어가야 함
    #self = this랑 유사함
    #클래스 자기 자신의 것이라는 의미
    def __init__(self,name,age):
        self.name = name
        self.age = age
    def __del__(self):
        print('memory 삭제')
    def introduce(self):
        print(f"이름:{self.name}, 나이:{self.age}")

s = Student("이동준",34)
s.introduce()
del s #명시적 삭제
s2 = Student(age=40, name="김동준")
s2.introduce()