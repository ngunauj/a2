/* ***********************************************
Author        :guanjunace@foxmail.com
Created Time  :2018年06月21日 星期四 10时24分20秒
File Name     :0004.cpp
题目大意：m个测试，每个测试n个数，代表n的行李箱的重量，问能不能把这n个行李箱分2部分，使得2部分的重量相等
************************************************ */

#include <bits/stdc++.h>
using namespace std;
int dp[30][210];
int a[30];
int main() {
	int t;
	char s;
	cin >> t;
	while (t--) {
		int i = 0;
		int sum = 0, x;
		while (~scanf("%d%c",&x,&s)) {
			a[++i] = x;
			sum += x;
			if (s == '\n') break;
		}
		//cout << sum << endl;
		if (sum&1) {
			puts("NO");
			continue;
		}
		memset(dp, 0, sizeof dp);
		for (int ii = 1; ii <= i; ++ii) {
			for (int j = 1; j <= sum/2; ++j) {
				if (j < a[ii]) dp[ii][j] = dp[ii-1][j];
				else dp[ii][j] = max(dp[ii-1][j], dp[ii-1][j-a[ii]] + a[ii]);
			}
		}
		if (dp[i][sum/2] == sum/2) puts("YES");
		else puts("NO");
	}
	return 0;
}
