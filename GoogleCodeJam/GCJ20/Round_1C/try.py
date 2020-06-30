from random import *

l = [0]*10
for i in range(10000):
  m = randint(1,pow(10,16)-1)
  n = randint(1,m)
  s = str(n)
  # print s
  l[ord(s[0])-ord('0')] += 1

print(l)