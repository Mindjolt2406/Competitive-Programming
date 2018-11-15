from random import *
#n = randrange(5,10)
#k = randrange(1,12)
n = int(raw_input())
k1 = int(raw_input())
l = []
m = []
#for i in range(n): l.append(randrange(1,12))
l = map(int,raw_input().split())
prod = 1
count = 0
for i in range(1,n+1):
    for  j in range(n-i+1):
        prod = 1
        for k in range(j,i+j):
            prod*=l[k]
            prod%=13
        print "i: ",i," j: ",j," prod: ",prod," k: ",k1
        if k1==prod: 
            count+=1
            m.append((i,j))

print "n: ",n," k: ",k1
for i in range(n):print l[i],
print ""
print "count: ",count
for i in m:
    print i[0],i[1]
