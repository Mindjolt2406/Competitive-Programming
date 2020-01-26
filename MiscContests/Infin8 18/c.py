l = [0,1,1]+[0]*(10**5-2)
for i in range(3,10**5+1):
    if (i)%4==3:l[i] = (l[i-1]+l[i-2]+2*((i/4)+1))%(10**9+7)
    elif i%4==2:l[i] = l[i-1]
    else:l[i] = (l[i-1]+l[i-2]+1)%(10**9+7)
n = int(raw_input())
print l[n]
