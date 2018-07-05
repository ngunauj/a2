/* ***********************************************
Author        :guanjunace@foxmail.com
Created Time  :2018年07月05日 星期四 09时13分16秒
File Name     :0214.cpp
************************************************ */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll sum[5010];
ll a;
ll dp[5010][2];
int main() {
	int n, m, k;
	while (cin >> n >> m >> k) {
		sum[0] = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> a;
			sum[i] = sum[i-1] + a;
		}
		for (int j = 1; j <= k; ++j) {
			for (int i = m; i <= n; ++i) {
				dp[i][j&1] = max(dp[i-1][j&1], dp[i-m][(j-1)&1] + sum[i] - sum[i-m]);
			}
		}
		cout << dp[n][k&1] << endl;
	}
	return 0;
}

