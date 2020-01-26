from random import *

n = randint(2,10)
m = randint(2,10)

print n,m

for i in range(n):
  s = ""
  for j in range(m):
    a = randint(0,7)
    if(a<7): s+="."
    else: s += "*"
  print s
