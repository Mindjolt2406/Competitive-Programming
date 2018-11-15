import sys
def enqueue(l,n):
    return l+[n]

def dequeue(l):
    return l[1:]

n,k = map(int,raw_input().split())
l = map(int,raw_input().split())
m = []
queue = []
index = []
#Construct the queue
end = -1
if n==1 or k==1:print 0;sys.exit()
for i in range(min(n,k)): #o build it
    print queue
    if end==-1:queue = enqueue(queue,l[i]);index=enqueue(index,i);end+=1
    elif queue[end]<l[i]:
        while end>-1 and queue[end]<l[i]:
            queue.pop()
            index.pop()
            end-=1
        queue = enqueue(queue,l[i])
        index = enqueue(index,i)
        end+=1
    elif queue[end]>=l[i]:queue = enqueue(queue,l[i]);index=enqueue(index,i);end+=1
if index[0]==k-1:queue = dequeue(queue);index = dequeue(index);end-=1
#bool = True
for i in range(k,k+n):
    #bool = False
    if i<n:print queue,end,m,l[i],index,i
    if queue!=[]:m.append(queue[0])
    #if queue[0]==l[i]:m.append()
    if end>-1 and index[0]-i<=(0): queue = dequeue(queue);index = dequeue(index);end-=1
    if i<n:
        if end==-1:queue = enqueue(queue,l[i]);index=enqueue(index,i);end+=1
        elif queue[end]<l[i]:
            print "Entered"
            while end>-1 and queue[end]<l[i]:
                print queue
                queue.pop()
                index.pop()
                end-=1
            print l[i],"Entered1",end,queue
            queue = enqueue(queue,l[i])
            index = enqueue(index,i)
            end+=1
        elif queue[end]>=l[i]:queue = enqueue(queue,l[i]);index=enqueue(index,i);end+=1
        if i==n-k+1:m.append(queue[end])

#if not bool:
m.append(0)
#else:m = queue
max1 = 0
#print m
if len(m)<len(l):
    k = len(l)-len(m)
    m+=[0]*k
for i in range(min(len(l),len(m))):
    if m[i]-l[i]>max1:max1 = m[i]-l[i];print l[i],m[i]
print l,m
print max1
