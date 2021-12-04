#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
	int n;
	cin >> n;
	vector<LL> price(n);
	for (auto &x: price) {
		cin >> x;
	}
	LL res = INT_MAX;
	set<LL> st;
	st.insert(price[0]);
	for (int i = 1; i < n; i++) {
		auto it = st.lower_bound(price[i]);
		if (it != st.end()) {
			res = min(res, *it - price[i]);
		}
		st.insert(price[i]);
	}
	cout << res << endl;
}

int main() {
    solve();
    return 0;
}

