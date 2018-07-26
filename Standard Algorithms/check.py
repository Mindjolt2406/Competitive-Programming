file1 = "Stress.out"
file2 = "Answer.out"

s = open(file1, 'r').readlines()
t = open(file2, 'r').readlines()

for i,j in zip(s,t):
    if(i[:len(i)-2]+i[len(i)-1]==j):
        continue
    else:
        print len(i),len(j)
        print i,j
    print "Here"
