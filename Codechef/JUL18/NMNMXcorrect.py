import sys
sys.setrecursionlimit(100000)
def C(n,k):
    p = dp[n][k];
    p1 = dp[n][n-k]
    if n==0: return 0
    elif(k==0 or n==k): return 1
    elif(k==1 or n-k==1):  return n
    if(dp[n][k]>=0): return p
    elif(dp[n][n-k]>=0): return p1
    dp[n][k] = (C(n-1,min(k-1,n-k)) + C(n-1,min(k,n-k-1)))
    dp[n][n-k] = dp[n][k]
    return dp[n][k];

# def C(n,k):
#     ans = 1
#     if(k>n-k): k = n-k
#     j = 1
#     while(j<=k):
#         if(n%j==0): ans*= (n/j)
#         elif(ans%j==0): ans = (ans/j)*n
#         else: ans = (ans*n)/j
#         j+=1
#         n-=1
#     return ans

def power(x,y,p):
    res = 1;
    x%=p
    while(y>0):
        if y&1:
            res = (res*x)%p;
        y = y>>1
        x = (x*x)%p
    return res

dp = []
MOD = 1000000007
for i in range(5002):
    dp.append([-1]*5002);

t = int(raw_input())
while(t):
    n,k = map(int,raw_input().split())
    l = []
    l = map(int,raw_input().split())
    l.sort()
    m = [0]*n
    c = C(n-1,k-1)
    for i in range(n): m[i] = c;
    left = 0
    right = k-1
    while(left<n-k+1):
        right = left+k-1
        while(right<n):
            c = C(right-left-1,k-2)
            m[left]-=c
            m[right]-=c
            right+=1
        left+=1
    for i in range(n):print m[i],
    print ""
    for i in range(n): m[i] = power(l[i],m[i],MOD)
    prod = 1
    for i in range(n):
        prod*=m[i]
        prod%=MOD
    print prod
    t-=1
