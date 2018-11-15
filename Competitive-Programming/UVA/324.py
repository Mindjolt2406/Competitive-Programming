import sys
l1 = sys.stdin.readlines()
s = ""
l = [1]
for i in range(1,1001): l.append(i*l[i-1])
for s in l1:
    n = int(s)
    s = s[:-1]
    if n==0: break;
    s1 = str(l[n])
    m = [0]*10
    for i in s1:
        m[ord(i)-ord('0')]+=1
    s+="! --"
    print(s)
    for i in range(0,5):
        if i==0: print("  ",end=" ")
        else: print("   ",end=" ")
        print("(%d)%5d"%(i,m[i]),end="")
        # print("   ("+str(i)+") " +str(m[i]),end=" ")
    print("")
    for i in range(5,10):
        # print("   ("+str(i)+") " +str(m[i]),end=" ")
        if i==5: print("  ",end=" ")
        else: print("   ",end=" ")
        print("(%d)%5d"%(i,m[i]),end="")
    print("")
