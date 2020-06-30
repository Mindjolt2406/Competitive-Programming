def sum(n):
  return (n*(n+1))/2

n = int(raw_input())
if n%2==0:
  print sum(n/2)+sum(n/2)
else:
  print sum(n//2)+n//2 +1 + sum(n//2)
