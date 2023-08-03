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


def calcCircle(r, PI):
    print(f"원넓이 : {r*r*PI}")
    print(f"원둘레 : {2*r*PI}")

def aTobSum(a,b):
    sum = 0
    for item in range(a,b+1):
        sum += item
    return sum
