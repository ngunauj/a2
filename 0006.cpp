/* ***********************************************
Author        :guanjunace@foxmail.com
Created Time  :2018年06月23日 星期六 10时20分32秒
File Name     :0006.cpp
************************************************ */
#include <bits/stdc++.h>
using namespace std;
int a[50], b[50]; // b duichen
int main() {
	int t, n;
	cin >> t;
	memset(a, 0, sizeof a);
	memset(b, 0, sizeof b);
	a[1] = 1;
	a[2] = 3;
	for (int i = 3; i <= 30; ++i) {
		a[i] = a[i-1] + 2*a[i-2];
	}
	for (int i = 2; i <= 30; ++i) {
		if (i&1) b[i] = a[i/2];
		else b[i] = a[i/2-1]*2 + a[i/2];
	}
	while (t--) {
		cin >> n;
		cout << (a[n] + b[n])/2 << endl;
	}
	return 0;
}
