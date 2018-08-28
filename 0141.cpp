/* ***********************************************
Author        :guanjunace@foxmail.com
Created Time  :2018年08月28日 星期二 09时15分51秒
File Name     :0141.cpp
************************************************ */
#include <bits/stdc++.h>
using namespace std;
int dp[2018][2018];
int main() {
	int T;
	cin >> T;
	while (T--) {
		char s[2018];
		char t[2018];
		//cin >> s >> t;
		scanf("%s%s",s+1, t+1);
		int n = strlen(s+1);
		int m = strlen(t+1);
		for (int i = 0; i <= n; ++i) {
			dp[i][0] = i;
		}
		for (int j = 0; j <= m; ++j) {
			dp[0][j] = j;
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (s[i] == t[j]) dp[i][j] = dp[i-1][j-1];
				else dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]),dp[i][j-1])+1;
			}
		}
		cout << dp[n][m] << endl;
	}
	return 0;
}
