/* ***********************************************
Author        :guanjunace@foxmail.com
Created Time  :2018年06月28日 星期四 09时38分15秒
File Name     :0469.cpp
************************************************ */
#include <bits/stdc++.h>
using namespace std;
long long cost[110][110];
int a[110];
long long dp[110][110][110];
#define INF 0x3f3f3f3f3f3f3f3f
int main() {
	int n, m, w;
	while (cin >> n >> m >> w) {
		long long ans = INF;
		memset(dp, INF, sizeof dp);
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}		
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				cin >> cost[i][j];
			}
		}
		if (a[1]) dp[1][1][a[1]] = 0;
		else {
			for (int i = 1; i <= m; ++i) {
				dp[1][1][i] = cost[1][i];
			}
		}
		for (int i = 2; i <= n; ++i) {
			for (int j = 1; j <= w; ++j) {
				if (a[i]) {
					dp[i][j][a[i]] = dp[i-1][j][a[i]];
					for (int t = 1; t <= m; ++t) {
						if (t != a[i]) dp[i][j][a[i]] = min(dp[i][j][a[i]], dp[i-1][j-1][t]);
					}
				} else {
					for (int k = 1; k <= m; ++k) {
						for (int t = 1; t <= m; ++t) {
							if (k != t) {
								dp[i][j][k] = min(dp[i][j][k], dp[i-1][j-1][t] + cost[i][k]);
							} else {
								dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][t] + cost[i][k]);
							}
						}
						//cout << dp[i][j][k] << endl;
					}
				}
			}
		}
		for (int i = 1; i <= m; ++i) {
			ans = min(ans, dp[n][w][i]);
		}
		if (ans == INF) puts("-1");
		else cout << ans << endl;
	}
	return 0;
}
