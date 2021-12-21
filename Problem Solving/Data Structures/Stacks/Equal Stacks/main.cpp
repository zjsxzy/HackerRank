#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;
	map<int, int> height;
	vector<int> h(n1), sum(n1);
	for (auto& x: h) {
		cin >> x;
	}
	sum[n1 - 1] = h[n1 - 1];
	height[sum[n1 - 1]]++;
	for (int i = n1 - 2; i >= 0; i--) {
		sum[i] = sum[i + 1] + h[i];
		height[sum[i]]++;
	}
	h.resize(n2); sum.resize(n2);
	for (auto& x: h) {
		cin >> x;
	}
	sum[n2 - 1] = h[n2 - 1];
	height[sum[n2 - 1]]++;
	for (int i = n2 - 2; i >= 0; i--) {
		sum[i] = sum[i + 1] + h[i];
		height[sum[i]]++;
	}
	h.resize(n3); sum.resize(n3);
	for (auto& x: h) {
		cin >> x;
	}
	sum[n3 - 1] = h[n3 - 1];
	height[sum[n3 - 1]]++;
	for (int i = n3 - 2; i >= 0; i--) {
		sum[i] = sum[i + 1] + h[i];
		height[sum[i]]++;
	}
	int res = 0;
	for (auto& [k, v]: height) {
		if (v == 3) res = max(res, k);
	}
	cout << res << endl;
}

int main() {
    solve();
    return 0;
}

