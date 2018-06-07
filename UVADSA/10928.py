t = input()
t = int(t)
for h in range(t):
    if(h!=0): k = input()
    n = input()
    n = int(n)
    l = []
    for i in range(n):
        l.append(list(input().split()))
    min1 = 1001
    for i in range(n):
        if(len(l[i])<min1): min1 = len(l[i])
    m = []
    for i in range(n):
        if len(l[i])==min1:
            m.append(i)
    s=""
    for i in m:
        s+=str(i+1)+" "
    print(s[:len(s)-1])
