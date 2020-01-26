file1 = "WA.out"
file2 = "AC.out"

s = open(file1, 'r').read().split()
t = open(file2, 'r').read().split()

print s != t
