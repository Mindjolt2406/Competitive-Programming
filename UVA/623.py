import sys
l1 = sys.stdin.readlines()
s = ""
l = [1]
for i in range(1,1001): l.append(i*l[i-1])
for s in l1:
    n = int(s)
    s = s[:-1]
    s+="!"
    print(s)
    print(l[n])
