n,s = map(int, raw_input().split())
dp = [[0 for i in range(550)] for i in range(52)]
dp[0][0] = 1
if s%2 == 1 or s/9 > 2*n:
	print 0
else:
	for i in range(1, n+1):
		for j in range(0, s//2+1):
			for k in range(0, min(j+1,10)):
				dp[i][j] += dp[i-1][j-k]
	print dp[n][s//2] **2

