l = map(int,raw_input().split())
d = {}
for i in range(1024):
  a = str(bin(i))
  a = a[2:]
  # print len(a)
  a = '0'*(10-len(a)) + a
  # print i,a
  sum1,sum2 = 0,0
  for j in range(len(a)):
    if a[j]=='1':
      sum1+=l[j]
    d[a] = sum1

count = 0
for i in d:
  for j in d:
    count+=1
    boo = 0
    if(i==j): continue
    if(('1','1') in zip(i,j)): break
    # if boo==1: break
    # print d[i],d[j],i,j
    if(d[i]==d[j]):
      print i,j,d[i],d[j]
print count