/* ***********************************************
Author        :guanjunace@foxmail.com
Created Time  :2018年06月26日 星期二 10时22分55秒
File Name     :0015.cpp
************************************************ */
#include <bits/stdc++.h>
using namespace std;
long long dp[55][550];
int main() {
	int n, s;
	while (cin >> n >> s) {
		memset(dp, 0, sizeof dp);
		dp[0][0] = 1;
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j <= s/2; ++j) {
				for (int k = 0; k <= min(j, 9); ++k) {
					dp[i][j] += dp[i-1][j-k];
				}
			}
		}
		if (s&1 || s/9 > 2*n) cout << 0 << endl;
		else cout << dp[n][s/2] * dp[n][s/2] << endl;
	}
	return 0;
}
