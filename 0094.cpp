/* ***********************************************
Author        :guanjunace@foxmail.com
Created Time  :2018年07月06日 星期五 09时18分23秒
File Name     :0094.cpp
************************************************ */
#include <bits/stdc++.h>
using namespace std;
int dp[2010][2010];
#define inf 0x3f3f3f3f
int main() {
	string s, t;
	int k;
	while (cin >> s >> t >> k) {
		//memset(dp, inf, sizeof dp);
		for (int i = 0; i <= s.size(); ++i) dp[i][0] = i*k;
		for (int i = 0; i <= t.size(); ++i) dp[0][i] = i*k;

		for (int i = 1; i <= s.size(); ++i) {
			for (int j = 1; j <= t.size(); ++j) {
				dp[i][j] = min(dp[i-1][j-1]+abs(s[i-1]-t[j-1]), min(dp[i-1][j], dp[i][j-1])+k);
			}
		}
		//int x = max(s.size(), t.size());
		cout << dp[s.size()][t.size()] << endl;
	}
	return 0;
}
