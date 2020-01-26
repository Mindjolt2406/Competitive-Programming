n,m = map(int,raw_input().split())
c,d = -1,-1
for h in range(n):
  a,b = map(int,raw_input().split())
  if c==-1 and a!=0:print "NO";exit()
  elif c==-1:c,d = a,b;continue
  elif d>b:continue
  elif c<=a<=d:c,d = a,b;continue
  else:
    print "NO";exit()

if c<=m<=d:print "YES"
else:print "NO"