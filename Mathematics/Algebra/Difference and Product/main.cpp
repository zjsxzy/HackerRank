#include <bits/stdc++.h>

using namespace std;

void solve() {
	int d, p;
	cin >> d >> p;
	int sign = 1;
	if (d < 0) {
		cout << 0 << endl;
		return;
	}
	if (p == 0) {
		cout << 4 << endl;
		return;
	}
    long long t = (long long)d * d + 4LL * p;
    if ((long long)sqrt(t) * (long long)sqrt(t) == t) {
        int res = 2;
        if (d && t) res += 2;
        cout << res << endl;
    } else {
        cout << 0 << endl;
    }
}

int main() {
	int ts;
	cin >> ts;
	while (ts--) {
		solve();
	}
	return 0;
}
