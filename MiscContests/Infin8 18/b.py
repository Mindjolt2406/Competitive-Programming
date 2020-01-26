def is_prime(n):
  if n == 2 or n == 3: return True
  if n < 2 or n%2 == 0: return False
  if n < 9: return True
  if n%3 == 0: return False
  r = int(n**0.5)
  f = 5
  while f <= r:
    if n%f == 0: return False
    if n%(f+2) == 0: return False
    f +=6
  return True 

n,k = map(int,raw_input().split())
if n==1:
    print "no"
elif k==1:
    if is_prime(n):
        print "yes"
    else:
        print "no"
else:
    if is_prime(n):
        print "yes"
    elif n%2==0:
        print "yes"
    elif k==2:
        if is_prime(n-2):
            print "yes"
        else:
            print "no"
    else:
        print "yes"
        exit()
        while k>=2:
            if is_prime(n-2):
                print "yes"
                break
            else:
                k-=1
                n-=2

