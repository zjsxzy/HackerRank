#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> s(n);
	vector<int> rem(k);
	for (auto &x : s) {
		cin >> x;
		rem[x % k]++;
	}
	if (k % 2 == 0) {
		rem[k / 2] = min(rem[k / 2], 1);
	}
	int res = min(rem[0], 1);
	for (int i = 1; i <= k / 2; i++) {
		res += max(rem[i], rem[k - i]);
	}
	cout << res << endl;
}

int main() {
    solve();
    return 0;
}

