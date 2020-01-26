import time
def fibo(n):
    global l
    if n==0:
        l[0] = 0
    if n==1:
        l[1] = 1
    if l[n] is not None:
        return l[n]
    l[n]= fibo(n-1)+fibo(n-2)
    return l[n]


global l
#l = [None]*41
#start = time.time()
while True:
    n = int(raw_input())
    l = [None]*(n+1)
    fibo(n)
#k= time.time()-start
    print l[n]
#print k
