#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	b[0] = a[0];
	for (int i = 1; i < n; i++) {
		int g = gcd(a[i - 1], a[i]);
		b[i] = a[i] * a[i - 1] / g;
	}
	b[n] = a[n - 1];
	for (int i = 0; i <= n; i++) {
		cout << b[i] << " ";
	}
	cout << endl;
}

int main() {
	int ts;
	cin >> ts;
	while (ts--) {
		solve();
	}
	return 0;
}
