def solution(l):
  n = len(l)
  after = [0]*n
  before = [0]*n
  for i in range(n):
    for j in range(i+1,n):
      if(l[j]%l[i] == 0): 
        after[i] += 1
    for j in range(0,i):
       if(l[i]%l[j] == 0): 
        before[i] += 1
  
  answer = 0
  for i in range(n):
    answer += before[i]*after[i]

  return answer 


if(__name__ == "__main__"):
  print solution([1, 2, 3, 4, 5, 6])
  print solution([1, 1, 1])