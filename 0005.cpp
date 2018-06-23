/* ***********************************************
Author        :guanjunace@foxmail.com
Created Time  :2018年06月21日 星期四 11时26分48秒
File Name     :0005.cpp
************************************************ */
#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int f(int num) {
	int sum = 0;
	while (num) {
		sum += num % 10;
		num /= 10;
	}
	return sum;
}
ll dfs(ll x) {
	if (x <= 0) return 0;
	else {
		int d = x%10;
		ll k  = x/10;
		return 10*dfs(k) + 45*k + d*f(k) + d*(d-1)/2;
	}
}
int main() {
	int  n, l, r;
	while (cin >> l >> r && l != -1 && r != -1) {
		cout << dfs(r) - dfs(l-1)<< endl;
	}
	return 0;
}
