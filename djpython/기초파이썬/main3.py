import Student

a = Student.Student("이동준",34)
a.introduce()
Student.calcCircle(5,3.14)

from Student import *
b = Student(name="김신혁",age=20)
calcCircle(10,3.1415)
b.introduce()

import Student as s

c = s.Student("소병수",30)
c.introduce()
print(s.aTobSum(1,100))
