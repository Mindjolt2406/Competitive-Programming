def sort1(l):
        if len(l)==1:
		return l
	c = (len(l)-1)/2
        m =  merge(sort1(l[:c+1]),sort1(l[c+1:])) 
        return m
def merge(l,m):
        global count
        #print l,m
        a,b = len(l),len(m)
        i,j = 0,0
        c = []
        while i<a or j<b:
            if i==a:
                c.append(m[j])
                j+=1
            elif j==b:
                c.append(l[i])
                count+=(j)
                i+=1
            elif l[i]<m[j]:
                c.append(l[i])
                count+=j
                i+=1
            else:
                c.append(m[j])
                j+=1
        #print count
        #print c,"sorted from ",l,m
        return c
t = int(raw_input())
global count
for _ in range(t):
        _1 = raw_input()
        count = 0
        n = int(raw_input())
        l = []
        for i in range(n):
            l.append(int(raw_input()))
        l = sort1(l)
        print count
#[8,7,6,5,4,3,2,1]	
