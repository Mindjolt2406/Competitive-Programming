n = int(raw_input())
s = raw_input()

if(n%2==0):
  a = n/2
  while(a<n and s[a]=='0'):
    a+=1

  if(a!=n): b =  long(s[:a]) + long(s[a:])
  else: b = -1

  a = n/2-1
  while(a+1<n and a>=0 and s[a+1]=='0'):
    a-=1
  
  if(a>=0): c = long(s[:a+1]) + long(s[a+1:])
  else: c = -1
  
  if(b!=-1 and c!=-1): print min(b,c)
  elif (b==-1): print c
  else: print b

else:
  a = n/2
  while(a<n and s[a]=='0'):
    a+=1

  if(a!=n): b =  long(s[:a]) + long(s[a:])
  else: b = -1
  
  a = n/2
  while(a+1<n and a>=0 and s[a+1]=='0'):
    a-=1
  
  if(a>=0): c = long(s[:a+1]) + long(s[a+1:])
  else: c = -1
  
  # print b,c
  if(b!=-1 and c!=-1): print min(b,c)
  elif (b==-1): print c
  else: print b

