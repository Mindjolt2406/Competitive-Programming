from random import *

n = randint(1,1000)
m = randint(n,1000)

print n,m

max1,max2,max3 = -1,-1,-1

for i in [n,m]:
  for j in range(n,m+1):
    if(i^j > max1):
      max2,max3 = i,j
      max1 = i^j

print max1
# print "XOR:",max1,"Pair:",max2,max3 