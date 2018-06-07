''''''
n = int(raw_input())
l = map(int,raw_input().split())
d = {}
for i in range(n):
    d[l[i]] = i
index = -1 #Idex of max1
m = []
c = [-1]*n
for i in range(n):
    print m
    if index>-1 and l[i]<m[index]:
        while index>-1 and l[i]<m[index]:
            c[d[m[index]]] = i
            m.pop()
            index-=1
        m.append(l[i])
        index+=1
    else:
        index+=1
        m.append(l[i])

for i in c:
    print i,
