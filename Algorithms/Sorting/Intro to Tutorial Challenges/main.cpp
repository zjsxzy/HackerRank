#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
	int v, n;
	cin >> v >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (v == x) {
			cout << i << endl;
			return;
		}
	}
}

int main() {
    solve();
    return 0;
}

