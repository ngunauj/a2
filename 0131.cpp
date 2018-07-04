/* ***********************************************
Author        :guanjunace@foxmail.com
Created Time  :2018年06月15日 星期五 09时59分17秒
File Name     :131.cpp
************************************************ */
#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int>& a) {
	int len = a.size();
	vector<int> dp(len, 0);
	dp[0] = a[0];
	for (int i = 1; i < len; ++i) {
		if (i >= 2) dp[i] = max(dp[i-2] + a[i], dp[i-1]); 
		else dp[i] = max(a[i-1], a[i]);
		//cout << dp[i] << "-" << endl;
	}
	return dp[len - 1];
}

int main() {
	int n, m, x;
	while (cin >> n >> m && n && m) {
		vector<int> v;
		for (int i = 0; i < n; ++i) {
			vector<int> a;
			for (int j = 0; j < m; ++j) {
				cin >> x;
				a.push_back(x);
			}
			//cout << solve(a) << endl;
			v.push_back(solve(a));
		}
		cout << solve(v) << endl;
	}
	return 0;
}

