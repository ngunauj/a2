/* ***********************************************
Author        :guanjunace@foxmail.com
Created Time  :2018年08月30日 星期四 09时55分18秒
File Name     :0264.cpp
************************************************ */
#include <bits/stdc++.h>
using namespace std;
#define INF 1e18
int a[100010];
long long dp[100010][2];
string R(string s) {
	string r = s;
	reverse(r.begin(), r.end());
	return r;
}
int main() {
	int n;
	while (cin >> n) {
		int mark = 0;
		for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
		string s, t, r;
		dp[1][0] = 0;
		dp[1][1] = a[1];
		cin >> t;
		r = R(t);
		//cout << r << endl;
		for (int i = 2; i <= n; ++i) {
			cin >> s;
			dp[i][0] = dp[i][1] = INF;

			if (s < t) {
				if (R(s) >= t) dp[i][1] = min(dp[i][1], dp[i-1][0] + a[i]);
			}
			else {
				dp[i][0] = min(dp[i-1][0], dp[i][0]);
				if (R(s) >= t) dp[i][1] = min(dp[i][1], dp[i-1][0] + a[i]);
			}
			
			if (s < r) {
				if (R(s) >= r) dp[i][1] = min(dp[i][1], dp[i-1][1] + a[i]);
			} else {
				dp[i][0] = min(dp[i-1][1], dp[i][0]);
				if (R(s) >= r) dp[i][1] = min(dp[i][1], dp[i-1][1] + a[i]);
			}
			//cout << dp[i][0] << " " << dp[i][1] << endl;
			if (dp[i][0] >= INF && dp[i][1] >= INF) {
				mark = 1;
			}
			t = s;
			r = R(s);
		}
		if (mark) puts("-1");
		else {
			cout << min(dp[n][0], dp[n][1]) << endl;
		}

	}
	return 0;
}
