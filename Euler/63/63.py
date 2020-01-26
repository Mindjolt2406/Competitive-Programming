ans = 0

for i in range(1,21):
  for j in range(10):
    if(len(str(pow(j,i))) == i):
      ans += 1

print "ans :",ans