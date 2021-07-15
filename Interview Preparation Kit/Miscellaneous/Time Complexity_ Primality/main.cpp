#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void prime(int x) {
	if (x == 1) {
		cout << "Not prime" << endl;
		return;
	}
	if (x == 2) {
		cout << "Prime" << endl;
		return;
	}
	if (x % 2 == 0) {
		cout << "Not prime" << endl;
	} else {
		for (int i = 3; i <= sqrt(x) + 1; i += 2) {
			if (x % i == 0) {
				cout << "Not prime" << endl;
				return;
			}
		}
		cout << "Prime" << endl;
	}
}

void solve() {
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		prime(x);
	}
}

int main() {
    solve();
    return 0;
}

