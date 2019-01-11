import math
def f(a):
  return min(100000,a*(a-1)/2)*(100000/a)*math.log(100000/a,2)

max1 = -1
max2 = -1
for i in range(1,100001):
  if(f(i)>max1):
    max1 = f(i)
    max2 = i

print max1,max2