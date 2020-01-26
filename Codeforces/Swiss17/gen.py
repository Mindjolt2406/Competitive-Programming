from random import *

mod = 89898989898989898

n = 200000
print n

prod = 1
l = []
for i in range(n):
  l.append(prod)
  prod*=2
  prod %= mod

l.sort()
for i in l:
  print i,

print "" 