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

def searchother(s,t,a,l,d):#Given the hshtable for the first string, it will iterate through the hashes of the second and check if it's
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

s = raw_input()
t = raw_input()
MOD = 4084061


n,m = len(s),len(t)
if n>m:s,t = t,s;n,m = len(s),len(t)
beg = 1
end = n
mid = (beg+end)/2
longest = 0
while beg<=end:
    mid = (beg+end)/2
    d = search(s,n,mid)
    k = searchother(s,t,m,mid,d)
    if not k:
        end = mid-1
    else:
        beg = mid+1
        if k>longest:longest = k
print(longest)
