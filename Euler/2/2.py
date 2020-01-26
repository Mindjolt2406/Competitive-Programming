l = [0,2]
index = 1
while l[index]<4000000:
    l.append(4*l[index]+l[index-1])
    index+=1
print sum(l[:-1])
