/* ***********************************************
Author        :guanjunace@foxmail.com
Created Time  :2018年06月16日 星期六 11时17分37秒
File Name     :2.cpp
************************************************ */
#include <bits/stdc++.h>
using namespace std;
int dp[11][25][156];
int main() {
	int n, b, s;
	while (cin >> n >> b >> s && n && b && s) {
		for (int i = 1; i <= n; ++i) dp[1][i][i] = 1, dp[0][i][0] = 1;
		for (int i = 1; i <= b; ++i) {
			for (int j = 2; j <= n; ++j) {
				for (int k = 1; k <= s; ++k) {
					dp[i][j][k] = dp[i][j-1][k];
					if (k >= j) dp[i][j][k] += dp[i-1][j-1][k-j];
				}
			}
		}
		cout << dp[b][n][s] << endl;
	}
	return 0;
}
