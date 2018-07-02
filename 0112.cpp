/* ***********************************************
Author        :guanjunace@foxmail.com
Created Time  :2018年07月02日 星期一 09时24分17秒
File Name     :0112.cpp
************************************************ */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 500010;
#define ll long long 
ll a[maxn];
ll sum1[maxn];
ll sum2[maxn];
int main() {
	int n;
	while (cin >> n) {
		sum1[0] = sum2[0] = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			sum1[i] = sum1[i-1] + a[i];
		}
		ll tmp = sum1[n]/3;
		if (sum1[n] %3 !=0) {
			cout << 0 << endl;
			continue;
		}
		for (int i = 1; i <= n; ++i) {
		   	if (sum1[i] == 2*tmp) sum2[i] = 1;
		}
		for (int i = 1; i <= n; ++i) {
			sum2[i] += sum2[i-1]; //维护i前面有几个和为2*tmp
		}
		ll ans = 0;
		for (int i = 1; i <= n-2; ++i) {
			if (sum1[i] == tmp) {
				//cout << i << " " << sum2[n-1] << " " << sum2[i] << endl;
				ans += sum2[n-1] - sum2[i];
			}
		}
		cout << ans << endl;
	}
	return 0;
}
