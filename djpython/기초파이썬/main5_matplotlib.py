import matplotlib.pyplot as plt
#0부터 10까지의 값들을 10씩 곱한 것이 x
x = [a*10 for a in range(0,11)]
y = range(0,11)
plt.plot(x,y)
plt.show()