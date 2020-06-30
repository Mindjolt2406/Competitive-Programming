def solution(s):
  ans,cnt = 0,0
  for i in s:
    if(i == ">"):
      cnt+= 1
    elif(i == "<"):
      ans += cnt
  
  return (ans << 1)

if(__name__ == "__main__"):
  print solution(">----<")
  print solution("<<>><")