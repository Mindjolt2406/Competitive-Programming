def search(s,a,l,d,e,j):#Builds a hashtable for all size l substrings
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
        if hashs in d and e[hashs][0]!=j:
            d[hashs]+=1
            e[hashs] = [j,i]
        elif hashs not in d: d[hashs] = 1;e[hashs] = [j,i]
        hashs-=(ord(s[i]))*prod
        hashs*=k
        if i<a-l:hashs+=ord(s[i+l]);
        hashs%=MOD
    return [d,e]

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
beg = 1
end = max1
mid = (beg+end)/2
longest = 0
longest1 = 0
string1 = ''
d,e = {},{}
count = 0
while  beg<=end:
    mid = (beg+end)/2
    boo = True
    for i in range(n):
        if m[i]<mid:end = mid-1;continue
        d,e = search(l[i],m[i],mid,d,e,i)
    if count==max(d.values()):boo = False
    else:count = max(d.values())
    print count,mid
    if(count>=atleast and boo):
        beg = mid+1
        if mid>longest:longest = mid
    else:
        end = mid-1
print longest
