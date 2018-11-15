import sys
import time
start = time.time()
sys.setrecursionlimit(100000)
def C(n,k):
    p = dp[n][k];
    p1 = dp[n][n-k]
    if(dp[n][k]>=0): return p
    elif(dp[n][n-k]>=0): return p1
    if(k==0 or n==k): return 1
    elif(k==1 or n-k==1):  return n
    dp[n][k] = (C(n-1,min(k-1,n-k)) + C(n-1,min(k,n-k-1)))
    dp[n][n-k] = dp[n][k]
    return dp[n][k];

# def C(n,r):
#     return fact[n]/(fact[r]*fact[n-r])

MOD = 1000000007
dp = []
for i in range(5002):
    dp.append([-1]*5002);

# fact = []
# fact.append(1);
# for i in range(1,5001): fact.append(i*(fact[i-1]))
t = int(raw_input())
while(t):
    n,k = map(int,raw_input().split())
    l = []
    l = map(int,raw_input().split())
    l.sort()
    ##
    l1 = [0]*5001
    for i in range(5001):
        if(i>=k-3): l1[i] = C(i,k-3)
    for i in range(1,5001): l1[i]+=l1[i-1]
    ##
    m = [0]*n
    for i in range(1,n):
        if(n-2-i>=0):
            m[i]+=l1[n-2-i]
            m[n-i]-=l1[n-2-i]

    sum1 = 0
    prod = 1
    for i in range(n):
        sum1+=m[i]
        m[i] = sum1
        prod*= pow(l[i],sum1,MOD)
        prod%=MOD
    # for i in range(n): print m[i],
    # print ""
    print prod
    t-=1
