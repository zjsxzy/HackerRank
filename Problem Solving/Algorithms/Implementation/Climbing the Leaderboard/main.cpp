#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
	int n, m;
	cin >> n;
	set<int> st;
	vector<int> ranked;
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		if (st.find(x) == st.end()) {
			ranked.push_back(x);
			st.insert(x);
		}
	}
	sort(ranked.begin(), ranked.end());
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		auto it = ranked.end() - upper_bound(ranked.begin(), ranked.end(), x);
		cout << it + 1 << endl;
	}
}

int main() {
    solve();
    return 0;
}

