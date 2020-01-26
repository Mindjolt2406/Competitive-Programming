p = 990
l = []
while p>0:
    for i in range(999,0,-1):
        k = p*i
        s = str(k)
        n = len(s)
        if n%2==0:
            #print s,
            if s[:n/2]==s[n/2:][::-1]:
                l.append(int(s))
                
    p-=11
print max(l)
