import hashlib
import re

t = int(raw_input())
counter = 0
hashVal = "b754015b1f05de447a0915eea5238c1f3310a4826b3190d5b7fe4739bc3bc992"
for h in range(t):
  s = raw_input()
  new_str = ""
  for i in s:
    if(ord(i)<=ord('z') and ord(i) >= ord('a')): new_str += i
    elif(ord(i)<=ord('Z') and ord(i) >= ord('A')): new_str += i
    else: new_str += " "
    
  # print new_str
  l = [i.lower() for i in new_str.split()]
  
  for i in l:
    counter  += 1
    temp_str = "zenseCTF{"+i+"}"
    # print temp_str
    # print str(hashlib.sha256(temp_str.encode()).hexdigest())
    if(hashVal == str(hashlib.sha256(temp_str.encode()).hexdigest())):
      print temp_str
      break

print(counter)