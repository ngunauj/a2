#include <bits/stdc++.h>
using namespace std;
// nlogn
int main() {
	int n;
	while (cin >> n) {
		vector<int> a(n, 0);
		vector<int> d(n, 0);
		for (int i = 0; i < n; ++i) cin >> a[i];
		int len = 1;
		d[1] = a[0];
		for (int i = 1; i < n; ++i) {
			if (a[i] > d[len]) d[++len] = a[i];
			else {
				int pos = lower_bound(d.begin(), d.begin() + len, a[i]) - d.begin();
				d[pos] = a[i];
			}
		}
		cout << len << endl;
	}
	return 0;
}

