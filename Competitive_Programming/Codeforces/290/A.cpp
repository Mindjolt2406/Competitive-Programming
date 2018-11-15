n,m = map(int,raw_input().split())
for i in range(n):
  if i%2==0:
    print "#"*m
  elif i%4==1:
    print "."*(m-1)+"#"
  elif i%4==3:
    print "#"+"."*(m-1)
