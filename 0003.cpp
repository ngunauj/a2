/* ***********************************************
Author        :guanjunace@foxmail.com
Created Time  :2018年06月18日 星期一 10时26分02秒
File Name     :0003.cpp
************************************************ */
#include <bits/stdc++.h>
using namespace std;
string s, t;
string ans;
int dp[88][88];
int pre[88][88];
map<string, bool>mp[88][88];
set<string> se;

void dfs(int x, int y, string ans) {
	if (mp[x][y][ans]) return;
	if (x == 0 || y == 0) {
		se.insert(ans);
		return ;
	}
	if (s[x-1] == t[y-1]) {
		ans = s[x-1] + ans;
		dfs(x-1, y-1, ans);
	}
	else if (dp[x-1][y] > dp[x][y-1]) {
		dfs(x-1, y, ans);
	}
	else if (dp[x][y-1] > dp[x-1][y]) {
		dfs(x, y-1, ans);
	}
	else {
		dfs(x-1, y, ans);
		dfs(x, y-1, ans);
	}
	mp[x][y][ans] = true;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> s >> t;
		int n = s.size();
		int m = t.size();
		for (int i = 0; i <= n; ++i) pre[i][0] = 1, mp[i][0].clear(); // from top
		for (int j = 0; j <= m; ++j) pre[0][j] = -1, mp[0][j].clear(); // from left
		memset(dp, 0, sizeof dp);
		se.clear();
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				mp[i][j].clear();
				if (s[i-1] == t[j-1]) {
					dp[i][j] = dp[i-1][j-1]+1;
					pre[i][j] = 0;
				}
				else if (dp[i-1][j] > dp[i][j-1]) {
					dp[i][j] = dp[i-1][j];
					pre[i][j] = 1;
				}
				else {
					dp[i][j] = dp[i][j-1];
					pre[i][j] = -1;
				}
				//cout << pre[i][j] << " ";
			}
			//cout << endl;
		}
		string ans = "";
		dfs(n, m, ans);
		for (auto x : se) {
			cout << x << endl;
		}
		//if (T > 0) cout << endl;
	}
	return 0;
}
