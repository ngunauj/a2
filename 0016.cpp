/* ***********************************************
Author        :guanjunace@foxmail.com
Created Time  :2018年07月09日 星期一 10时08分46秒
File Name     :0016.cpp
************************************************ */
#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f; 
int val[520], cost[520];
int dp[10020];
int main() {
	int T,E,F;
	int V, n;
	cin >> T;
	while (T--) {
		cin >> E >> F;
		cin >> n;
		V = F - E;
		for (int i = 1; i <= n; ++i) {
			cin >> val[i] >> cost[i];
		}
		memset(dp, inf, sizeof dp);
		dp[0] = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = cost[i]; j <= V; ++j) {
				//dp[i][j] = min(dp[i-1][j], dp[i-1][j-cost[i]] + val[i]);
				dp[j] = min(dp[j], dp[j-cost[i]]+val[i]);
			}
		}
		if (dp[V] != inf) {
			printf("The minimum amount of money in the piggy-bank is %d.\n", dp[V]);
		}
		else {
			puts("This is impossible.");
		}
	}
	return 0;
}
