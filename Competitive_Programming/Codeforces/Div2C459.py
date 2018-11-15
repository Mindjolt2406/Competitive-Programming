def recur(s,n,i,j):
  global dp
  #print s,n,i,j
  if n<2 or n%2==1:dp[i][j] = -1;return False
  elif n==2 and s in ["()","??","(?","?)"]:
    return dp[i][j]
  elif n==2:dp[i][j] = -1;return False
  elif dp[i][j] == -1: return False
  elif dp[i][j]==1:return True
  for k in range(2,n,2):
    if recur(s[:k],k,i,i+k-1) and recur(s[k:],n-k,k+i,j):
      dp[i][j] = 1
      return dp[i][j]
  if s[0]+s[n-1] in ["()","??","(?","?)"] and recur(s[1:n-1],n-2,i+1,j-1):
    dp[i][j] = 1
    return dp[i][j]

  dp[i][j] = -1
  return False

s = raw_input()
n = len(s)
global dp
dp = [[False]*n for x in range(n)]
count = 0
for i in range(n-1):
  if s[i:i+2] in ["()","??","(?","?)"]:
#    print "NEtered"
    dp[i][i+1]  = True
#for i in range(n):
#  for  j in range(n):
#    if dp[i][j]:count+=1;print i,j,s[i:j+1]

if n%2==0:
    recur(s,n,0,n-1)
    for i in range(4,n+1,2):
      for j in range(n-i+1):
        recur(s[j:j+i],i,j,j+i-1)
else:
    recur(s[1:],n-1,1,n-1)
    recur(s[:n-1],n-1,0,n-2)
    k = s
    s = k[1:]
    n = len(s)
    for i in range(4,n+1,2):
      for j in range(n-i+1):
        recur(s[j:j+i],i,j+1,j+i)
    s = k[0:n-1]
    n = len(k)
    for i in range(4,n+1,2):
      for j in range(n-i+1):
        #print "recur",k[j:j+i]
        recur(s[j:j+i],i,j,j+i-1)
    s = k


for i in range(n):
  for  j in range(n):
    if dp[i][j]==1:count+=1#;print i,j,s[i:j+1]

print count
    
