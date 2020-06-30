s = raw_input()
a = long(s)

t = "0"+s
b = long(t[len(t)-2:len(t)])

b%=4

if(b == 0): 
  print a
elif(b == 1): 
  print 1
elif(b == 2): 
  print a^1
else: 
  print 0
