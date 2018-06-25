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
int n, m;
int dfs(int x, int y) {
	if (x == n && y == m) {
		return a[n][m];
	}
	if (x > n || y > m) return 1000000;
	if (dp[x][y] != 0) return dp[x][y];
	dp[x][y] = max(1, min(dfs(x+1, y), dfs(x, y+1)) - a[x][y]);
	return dp[x][y];
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		memset(dp, 0, sizeof dp);
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				cin >> a[i][j];
			}
		}
		a[n][m] = max(1, a[n][m]);
		cout << dfs(1, 1) << endl;
		/*
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
		*/
	}
	return 0;
}
