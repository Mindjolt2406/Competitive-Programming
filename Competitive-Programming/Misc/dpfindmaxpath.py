t = int(raw_input())
for _ in range(t):
	n,m = map(int,raw_input().split())
	l = []
	for i in range(n):
		l.append(map(int,raw_input().split()))
	dp = [[0]*m for x in range(n)]
	dp[0][0] = l[0][0]
	for i in range(1,m):
		dp[0][i] = dp[0][i-1]+l[0][i]
        for i in range(1,n):
		dp[i][0] = dp[i-1][0] + l[i][0]
	for i in range(1,n):
		for j in range(1,m):
			dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + l[i][j]
	print dp[n-1][m-1]
