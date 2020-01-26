def fcd(a,b):
  if(a==0):
    x,y = 0,1
    return [b,0,1]
  
  x1,y1 = 0,0
  d = gcd(b%a,a,x1,y1)
