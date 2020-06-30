def solution(n):
  dp[i][j][k] = i steps, having the sum height to be j with k as the last step
  dp[i][j][k] = sum over j',k' dp[i-1][j'][k'] where j'+ k' = j and k' < k

  dp = [[[0]*210 for i in range(210)] for j in range(210)]

  for i in range(1,n+1): dp[0][i][i] = 1

  for i in range(30):
    for j in range(1,n+1):
      for k in range(1,n+1):
        for k2 in range(1,k):
          if(j >= k2): dp[i][j][k] += dp[i-1][j-k2][k2]
  
  ans = 0
  for i in range(1,30):
    for j in range()


if(__name__ == "__main__"):
