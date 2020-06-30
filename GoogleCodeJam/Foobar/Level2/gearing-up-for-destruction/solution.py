
def gcd(x, y): 
  
   while(y): 
       x, y = y, x % y 
  
   return x 
   
MUL = 6

def solution(pegs):
  l = pegs
  n = len(l)
  if(n == 1): return [-1,-1]
  x = 0
  l = [MUL*x for x in l]
  # l = [x-l[0] for x in l]
  # print(l)
  
  poss = False
  for x in range(1,10010*MUL):
    prev = x
    boo = True
    for i in range(1,n):
      if((l[i]-l[i-1])-prev > 0):
        prev = (l[i]-l[i-1])-prev
      else:
        boo = False
        break

    if(boo):
      # print("x: ",x,"prev: ",prev)
      if(x == 2*prev):
        poss = True
        p = [x,MUL]
        g = gcd(x,MUL)
        p = [x/g for x in p]
        return p

    # print prev
  if(poss == False): return [-1,-1]

if __name__ == "__main__":
  l = map(int,raw_input().split())
  print(solution(l))
  # print solution([4, 9, 17, 31, 40])
  # print solution([4,30,50])