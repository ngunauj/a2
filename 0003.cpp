/* ***********************************************
Author        :guanjunace@foxmail.com
Created Time  :2018年06月18日 星期一 10时26分02秒
File Name     :0003.cpp
************************************************ */
#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > dp(1010, vector<int>(1010));
vector<vector<int> > pre(1010, vector<int>(1010));
string s, t;
void dfs(int x, int y, int len) {
	if (len == 0) {
		cout << endl;
		return ;
	}
	if (pre[x][y] == 0) {
		dfs(x-1, y-1, len-1);
		cout << s[x-1];
	}
	else if (pre[x][y] == 1) {
		dfs(x-1, y, len);
		cout << s[x-1];
	}
	else if (pre[x][y] == -1){
		dfs(x, y-1, len);
		cout << t[y-1];
	}
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> s >> t;
		int n = s.size();
		int m = t.size();
		for (int i = 0; i <= n; ++i) pre[i][0] = 1; // from top
		for (int j = 0; j <= m; ++j) pre[0][j] = -1; // from left

		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
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
		dfs(n, m, dp[n][m]);
		//if (T) cout << endl;
	}
	return 0;
}
