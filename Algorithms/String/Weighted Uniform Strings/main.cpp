#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
	string s;
	cin >> s;
	set<int> st;
	char c = s[0];
	int sum = c - 'a' + 1;
	st.insert(sum);
	for (int i = 1; i < SZ(s); i++) {
		if (s[i] == c) {
			sum += c - 'a' + 1;
		} else {
			c = s[i];
			sum = s[i] - 'a' + 1;
		}
		st.insert(sum);
	}
	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		if (st.find(x) == st.end()) {
			cout << "No" << endl;
		} else {
			cout << "Yes" << endl;
		}
	}
}

int main() {
    solve();
    return 0;
}

