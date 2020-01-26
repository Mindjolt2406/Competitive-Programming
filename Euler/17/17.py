#Brute force implementation
import time
import math
def findnumber(n):
    count = 0
    for i in range(1,long(n**0.5)+1):
        if n%i==0:
            #print i,n/i
            if n/i!=i:count+=2
            else:count+=1
    #if count>250:print count
    return count

start = time.time()
n = 10
while True:
    k = (n*(n-1))/2 
    #print k,time.time()-start
    if findnumber(k)>=500:
        #print k
        break
    elif findnumber(k)>400:
        print k
    n+=1
