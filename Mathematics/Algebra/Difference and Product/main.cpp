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
	if (p < 0) {
		sign = -1;
		p = sign * p;
	}
	int res = 0;
	for (int a = 1; a <= (int)sqrt(p); a++) {
		if (p % a == 0) {
			int b = p / a;
			if (abs(a - sign * b) == d) {
				res++;
				if (a != sign * b) res++;
			}
		}
	}
	if (sign == 1) res *= 2;
	cout << res << endl;
}

int main() {
	int ts;
	cin >> ts;
	while (ts--) {
		solve();
	}
	return 0;
} 
