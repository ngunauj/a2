/* ***********************************************
Author        :guanjunace@foxmail.com
Created Time  :2018年07月04日 星期三 09时28分09秒
File Name     :0097.cpp
************************************************ */
#include <bits/stdc++.h>
using namespace std;
const int N = 110;
const int inf = 0x3f3f3f3f;
int sum[N][N];
int dp[N];
int a[N][N];

int main() {
	int n;
	while (cin >> n) {
		memset(sum, 0, sizeof sum);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				cin >> a[i][j];
				sum[i][j] = sum[i][j-1] + a[i][j];
			}
		}
		int ans = -inf;
		for (int j = 1; j <= n; ++j) {
			for (int k = j; k <= n; ++k) {
				memset(dp, 0, sizeof dp);
				for (int i = 1; i <= n; ++i) {
					int x = sum[i][k] - sum[i][j-1];
					dp[i] = max(dp[i-1]+x, x);
					ans = max(dp[i], ans);	
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
