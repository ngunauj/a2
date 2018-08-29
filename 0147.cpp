/* ***********************************************
Author        :guanjunace@foxmail.com
Created Time  :2018年08月29日 星期三 09时46分28秒
File Name     :0147.cpp
************************************************ */
#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	string t = "hello";
	int j = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == t[j]) {
			++j;
			if (j >= 5) break;
		}
	}
	if (j == 5) puts("YES");
	else puts("NO");
	return 0;
}
