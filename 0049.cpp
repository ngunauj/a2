/* ***********************************************
Author        :guanjunace@foxmail.com
Created Time  :2018年07月10日 星期二 09时56分02秒
File Name     :0049.cpp
************************************************ */
#include <bits/stdc++.h>
using namespace std;
int a[100010];
int dp[100010];
int main() {
	int n;
	while (cin >> n) {
		for (int i = 1; i <= n; ++i) cin >> a[i];
		dp[0] = 0;
		a[0] = 0;
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			if (a[i] >= a[i-1]) {
				dp[i] = dp[i-1] + 1;
			}
			else dp[i] = 1;
			ans = max(ans, dp[i]);
		}
		cout << ans << endl;
	}
	return 0;
}
