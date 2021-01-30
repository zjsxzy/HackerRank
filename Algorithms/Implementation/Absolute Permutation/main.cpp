#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<bool> vst(n + 1);
	vector<int> res;
	for (int i = 1; i <= n; i++) {
		if (i - k >= 1 && !vst[i - k]) {
			vst[i - k] = true;
			res.push_back(i - k);
		} else if (i + k <= n && !vst[i + k]) {
			vst[i + k] = true;
			res.push_back(i + k);
		} else {
			cout << -1 << endl;
			return;
		}
	}
	for (auto &x : res) {
		cout << x << " ";
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

