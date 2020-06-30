l = raw_input().split()
s1,s2 = l
p = s2[0]
c = len(s1)
for i in range(1,len(s1)):
  if ord(s1[i])>=ord(s2[0]):
    c = i
    break
print s1[:c]+p
