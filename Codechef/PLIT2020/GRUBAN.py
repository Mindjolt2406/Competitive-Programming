t = int(raw_input())

for h in range(t):
  n,k = map(long,raw_input().split())
  max1 = -1

  l = []

  for i in range(1,100000):
    if(n%i == 0):
      l.append(i)
      l.append(n/i)
  
  l.sort()
  
  for i in l:
    c = (k*(k+1))/2

    if(i*c > n): continue
    if((n-i*c) % i !=0): continue
    max1 = i
  
  print max1