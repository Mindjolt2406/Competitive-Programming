import time
def fibo(n):
    if n==1:
        return 1
    if n==0:
        return 0
    return fibo(n-1)+fibo(n-2)
start = time.time()
print fibo(40)
print time.time()-start
