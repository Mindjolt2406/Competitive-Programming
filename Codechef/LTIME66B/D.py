t = int(raw_input())
for h in range(t):
  n,k = map(int,raw_input().split())
  m = [0]*n
  l = map(long,raw_input().split())
  for i in range(n): 
    l[i] = pow(k,l[i])
    m[i] = l[i]
  
  for i in range(1,n):
    l[i]+=l[i-1]
    m[n-1-i]+=m[n-i]
  
  max1 = -1
  max2 = -1
  for i in range(n-1):
    c = l[i]*m[i+1]
    # print i,i+1
    # print l[i],m[i+1]
    if(c>max1):
      max1 = c
      max2 = i
  
  # print l,m
  print max2+1
  
