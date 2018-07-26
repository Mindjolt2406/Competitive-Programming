lim = 999
l = [False,False,True] + [True]*(lim-3)
for i in range(len(l)):
    if l[i]:
        for j in range(2*i,lim,i):
            if j%i==0:l[j] = False
#for i in range(len(l)):
 #   if l[i]:print i,

m = []
for i in range(1,32):
    m.append(i**2-4)
for i in m:
     if l[i]:
         print i

#print l
#print m


#m = []
#count = 0
#for i in range(lim):
#    if l[i]:
#        count+=1
#        if count==10001:print i;break
        

