def power(x,y,p):
    res = 1
    x%=p
    while(y>0):
        if y&1:
            res = (res*x)%p
        y>>=1
        x = (x*x)%p
    return res

def gcd(a,b):
    if(b==0): return a
    if(a==0): return b
    while(b):
        a,b = b,a%b
    return a

t = int(raw_input())
MOD = 1000000007
for h in range(t):
    a,b,n = map(long,raw_input().split())
    if(a<b): a,b = b,a
    if(a==b):
        print (power(a,n,MOD)+power(b,n,MOD))%MOD
        continue
    c1 = (power(a,n,a-b) + power(b,n,a-b))%(a-b)
    print(gcd(c1,a-b)%MOD)
