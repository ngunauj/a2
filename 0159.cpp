/* ***********************************************
Author        :guanjunace@foxmail.com
Created Time  :2018年07月03日 星期二 08时56分56秒
File Name     :0159.cpp
************************************************ */
#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int maxn = 100005;
long long dp[maxn];
long long sum[maxn];
int main() {
	int n, k;
	cin >> n >> k;
	sum[0] = 1;
	dp[0] = 1;
	for (int i = 1; i < maxn; ++i) {
		if (i >= k) {
			dp[i] = (dp[i] + dp[i-k])%mod;
		} 
		dp[i] += dp[i-1]%mod;
		sum[i] = (sum[i-1] + dp[i])%mod;
	}
	int a, b;
	while (n--) {
		cin >> a >> b;
		cout << (sum[b] - sum[a-1] +mod) % mod<< endl;
	}

	return 0;
}
