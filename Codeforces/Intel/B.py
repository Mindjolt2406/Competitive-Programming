n = int(raw_input())
l = [int(x) for x in raw_input().split()]
boo = True

for i in range(n):
  m = raw_input().split()
  t = "aeiouy"
  cnt = 0
  for s in m:
    for j in s: 
      if(j in t): cnt += 1

  if(cnt != l[i]):
    boo = False
    break

if(boo):
  print "YES"
else:
  print "NO"