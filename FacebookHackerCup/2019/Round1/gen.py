from random import *
print 1
print 1000000,0
s = ""
for i in range(1000000): s+= chr(ord('A')+randint(0,1))
print s