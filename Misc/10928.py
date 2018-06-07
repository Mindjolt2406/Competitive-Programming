t = input()
for h in range(t):
    n = input()
    l = []
    for i in range(n):
        l.append(map(int,input().split()))
    min1 = 1001
    for i in range(n):
        if(len(l[i])<min1): min1 = len(l[i])
    m = []
    for i in range(n):
        if len(l[i]==min1):
            m.append(i)
    for i in m:
        print i,
    print ""
