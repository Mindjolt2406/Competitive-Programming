# import math
def gcd(a,b):
  while(b):
    a,b = b,a%b
  return a

t = int(raw_input())
l = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229,233, 239, 241, 251,257]
for h in range(t):
  n = long(raw_input())
  prod = 1
  index = -1
  for i in range(len(l)):
    if(prod*l[i]>n): 
      index = i
      break
    prod*=l[i]

  sum1 = 1
  for i in range(index):
    sum1+=(sum1*l[i])
  
  g = gcd(sum1,prod)
  # print prod,sum1
  prod/=g
  sum1/=g
  print str(prod)+"/"+str(sum1)