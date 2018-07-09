/* ***********************************************
Author        :guanjunace@foxmail.com
Created Time  :2018年07月07日 星期六 11时58分54秒
File Name     :0371.cpp
************************************************ */
#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
const int inf = 0x3f3f3f3f;
int dp[N][27];
int pre[N][27];
string s;

int main() {
	while (cin >> s) {
		memset(dp, inf, sizeof dp);
		memset(pre, 0, sizeof pre);
		for (int i = 0; i < 26; ++i) dp[0][i] = 1;
		dp[0][s[0]-'a'] = 0;
		for (int i = 1; i < s.size(); ++i) {
			int c = s[i]-'a';
			for (int j = 0; j < 26; ++j) {
				if (j > inf/2)continue;
				for (int k = 0; k < 26; ++k) {
					if (j == k) continue;
					int cost = c != j;
					//cout << cost << " " << c << " " << k << endl;
					if (dp[i-1][k] + cost < dp[i][j]) {
						dp[i][j] = dp[i-1][k] + cost;
						pre[i][j] = k;
					}
				}
			}
		}
		int ans = inf;
		int b = 0;
		for (int i = 0; i < 26; ++i) {
			//cout << dp[s.size()-1][i] << endl;
			if (dp[s.size()-1][i] < ans) {
				ans = dp[s.size()-1][i];
				b = i;
			}
		}
		int i,j;
		for (i = s.size()-1, j = b; i >= 0; j = pre[i][j],--i) {
			s[i] = 'a' + j;
		}
		cout << s << endl;	
	}	
	return 0;
}
