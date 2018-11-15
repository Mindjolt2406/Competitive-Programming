def search(s,a,l):#Builds a hashtable for all size l substrings
    a = int(a)
    l = int(l)
    if l==0:return {};
    MOD = 4084061
    hashs = 0
    prod = 1
    k = 255
    d = {}
    for i in range(int(l)):
        hashs*=k
        hashs+=ord(s[i])
        hashs%=MOD
        if(i!=l-1):prod*=k;prod%=MOD
    for i in range(a-l+1):
        if hashs in d:d[hashs].append(i)
        else: d[hashs] = [i]
        hashs-=(ord(s[i]))*prod
        hashs*=k
        if i<a-l:hashs+=ord(s[i+l]);
        hashs%=MOD
    return d

def searchother(s,t,a,l,d):#Given the hshtable for the first string, it will iterate through the hashes of the second and check if it's present in d
    a,l = int(a),int(l)
    if l==0:return 0
    MOD = 4084061
    hasht = 0
    prod = 1
    k = 255
    for i in range(l):
        hasht*=k
        hasht+=ord(t[i])
        hasht%=MOD
        if(i!=l-1):prod*=k;prod%=MOD

    for i in range(a-l+1):
        if hasht in d:
            for x in d[hasht]:
                boo = True
                for j in range(l):
                    if s[x+j]==t[j+i]:continue
                    else: boo = False;break
                if boo: return l;
        else:
            hasht-=(ord(t[i]))*prod
            hasht*=k
            if i<a-l:hasht+=ord(t[i+l]);
            hasht%=MOD
    return 0


# reading input

l = []
m = []
n,k = map(int,raw_input().split())
atleast = int(raw_input())
for i in range(k):
    l.append(raw_input())
    m.append(len(l[i]))
'''fname = 'input1.txt'

with open(fname, 'r') as f:
	text = f.read().split()

	for line in text:
		l.append(line)
		m.append(len(line))

n = len(l)
max1 = max(m)
# TODO write YOUR code here
# n is the total number of strings
# strings[i] is the i'th string
# lengths[i] is the length of the i'th string'''
'''n = len(l)
min1 = min(m)'''
n = len(l)
max1 = max(m)
for i in range(n):
    if m[i]==max1:t = l[i];break


beg = 1
end = max1
mid = (beg+end)/2
longest = 0
for t in l:
    while  beg<=end:
        mid = (beg+end)/2
        if len(t)<mid:end = mid-1;continue
        d = search(t,len(t),mid)
        count = 0
        for i in range(n):
            if mid<=m[i]:
                #print t,l[i]
                k = searchother(t,l[i],m[i],mid,d)
                if not k:continue
                else:count+=1;#print t,l[i]
        #print count,mid
        if(count>=atleast):
            beg = mid+1
            if mid>longest:longest = mid
        else:
            end = mid-1
print longest
