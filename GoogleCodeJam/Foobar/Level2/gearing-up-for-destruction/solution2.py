from fractions import Fraction  

def solution(pegs):
  l = pegs
  n = len(l)
  if(n==1 or not(l)): return [-1,-1]

  even  = False
  if(n%2 == 0): even = True

  sum1 = (l[0]+l[n-1])*(-1)
  if(even): sum1 = l[n-1]-l[0]
  
  if(n>2):
      for i in range(1, n-1):
            sum1 += 2 * (-1)**(i+1) * l[i]


  x = Fraction(2 * (float(sum1)/3 if even else sum1)).limit_denominator()
  
#   for x in range(1,(max1+10)*MUL):

  # if(x<2): return [-1,-1]

  # print x
  prev = x
  if(prev < 1): return [-1,-1]
  
  for i in range(0,n-2):
    new_prev = l[i+1]-l[i]-prev
    if(new_prev >= 1):
        prev = new_prev
    else:
        return [-1,-1]
    # if(new_prev < 1):
    #   return [-1,-1]
    # else:
    #   prev = new_prev
  
  return [x.numerator,x.denominator]

    # print prev
#   if(poss == False): return [-1,-1]

if __name__ == "__main__":
  l = map(int,raw_input().split())
  print(solution(l))
  # print solution([4,17,50])
  # print solution([4,30,50])