/* ***********************************************
Author        :guanjunace@foxmail.com
Created Time  :2018年06月29日 星期五 11时06分25秒
File Name     :0179.cpp
************************************************ */
#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long dp[110];
long long pre[110];
int main() {
	int n, k, d;
	while (cin >> n >> k >> d) {
		memset(dp, 0LL, sizeof dp);
		memset(pre, 0LL, sizeof pre);
		for (int i = 1; i <= k; ++i) {
			dp[i] = 1LL;
			if (i < d) pre[i] = 1LL;
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= k; ++j) {
				if (i >= j) {
					dp[i] = (dp[i] + dp[i-j])%mod;
					if (j < d) pre[i] = (pre[i] + pre[i-j])%mod;
				}
			}
		}
		//cout << dp[n] << endl;
		//cout << pre[n] << endl;
		cout << (dp[n] - pre[n] + mod)%mod << endl;
	}
	return 0;
}
