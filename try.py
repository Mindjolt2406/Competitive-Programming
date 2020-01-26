l = [0,0,0,0]
for i in range(25):
  print i
  m = raw_input().split()
  # print m,m[0]
  l[int(m[0])-1]+=1

print l