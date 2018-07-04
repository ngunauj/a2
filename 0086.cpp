/* ***********************************************
Author        :guanjunace@foxmail.com
Created Time  :2018年07月04日 星期三 09时10分54秒
File Name     :0086.cpp
************************************************ */
#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,k,l,c,d,p,nl,np;
	while (cin >> n >> k >> l >> c >> d >> p >> nl >> np) {
		int tl = k * l;
		int tc = c * d;
		int tp = p;
		cout << min (tl/nl, min(tp/np, tc)) / n << endl;
	}
	return 0;
}
