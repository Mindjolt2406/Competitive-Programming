l = map(int,raw_input().split())
max1 = 0
m = []
for i in range(len(l)):
    #print m
    if l[i]>max1:
        m.extend(range(max1+1,l[i]+1))
        max1 = max(l[:i+1])
        m.pop()
    elif i==0:
        m.extend(range(1,l[i]+1))
        m.pop()
    else:
        if l[i]==m[len(m)-1]:m.pop()
        else:print "NO";exit()
print "YES"
