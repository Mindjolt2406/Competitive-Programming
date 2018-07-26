from random import *

n = 10
m = 10
print n,m
for i in range(n): print randint(1,10),
print ""
for i in range(m-1):
    c = 2
    print c,
    if c==1: print randint(1,n),randint(1,10)
    elif c==2: print randint(1,n),randint(1,n)
    else: print randint(1,n),randint(1,n),randint(1,10)
print 3,randint(1,n),randint(1,n),randint(1,10)
