s = raw_input()
t = raw_input()#Substring
MOD = 4084061

k = 26
a,b = len(s),len(t)
hashs,hasht = 0,0
prod = 1
for i in range(b):
    hashs*=k;
    hasht*=k;
    hashs+=ord(s[i])-97;hashs%=MOD
    hasht+=ord(t[i])-97;hasht%=MOD
    if(i!=b-1):prod*=k;prod%=MOD


for i in range(a-b+1):
    if hashs==hasht:
        boo = True
        for j in range(b):
            if s[i+j]==t[j]:continue
            else: boo= False;break;
        if boo:print "YES";exit()
    else:
        hashs-=((ord(s[i])-97))*prod
        hashs*=k;
        if i<a-b:hashs+=ord(s[i+b])-97;
        hashs%=MOD
print "NO"
