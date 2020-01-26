import time
def fibo(n):
    l[0] = 0
    l[1]  =1
    for i in range(2,n+1):
        l[i] = l[i-1]+l[i-2]
    return l[n]
n = int(raw_input())
l = [None]*(n+1)
start = time.time()
print fibo(n)
print time.time()-start
