sum1 = 0
for i in range(3,1001,3):
    sum1+=i
    print i,
for i in range(5,1001,5):
    if i %3==0:continue
    sum1+=i
    print i,
print ""
print sum1
