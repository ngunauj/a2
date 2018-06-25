/* ***********************************************
Author        :guanjunace@foxmail.com
Created Time  :2018年06月25日 星期一 09时50分02秒
File Name     :0019.cpp
************************************************ */
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int dp[510][510];
int a[510][510];
int pre[510][510];
int ans = 0;

void dfs(int x, int y) {
	if (x == 1 || y == 1) {
		return ;
	}
	if (pre[x][y] == -1) {
		if (a[x][y] < 0) ans = max(abs(a[x][y]-dp[x-1][y]), ans);
		dfs(x-1, y);
	}
	else if (pre[x][y] == 1) {
		if (a[x][y] < 0) ans = max(abs(dp[x][y]-dp[x][y-1]), ans);
		dfs(x, y-1);
	}
}

int main() {
	int t, n, m;
	cin >> t;
	while (t--) {
		ans = 0;
		memset(dp, -INF, sizeof dp);
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				cin >> a[i][j];
			}
		}

		for (int i = 0; i <= m; ++i) dp[0][i] = 0;
		for (int i = 0; i <= n; ++i) dp[i][0] = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (dp[i-1][j] > dp[i][j-1]) {
					dp[i][j] = dp[i-1][j];
					pre[i][j] = -1;
				}
				else {
					dp[i][j] = dp[i][j-1];
					pre[i][j] = 1;
				}
				dp[i][j] += a[i][j];
			}
		}
		dfs(n, m);
		cout << ans << endl;
	}
	return 0;
}
