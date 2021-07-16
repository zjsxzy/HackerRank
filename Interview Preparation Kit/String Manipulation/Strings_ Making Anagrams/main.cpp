#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
	string a, b;
	cin >> a >> b;
	map<char, int> cnta, cntb;
	for (int i = 0; i < 26; i++) {
		cnta[i + 'a'] = 0;
		cntb[i + 'a'] = 0;
	}
	for (auto &c: a) {
		cnta[c]++;
	}
	for (auto &c: b) {
		cntb[c]++;
	}
	int res = 0;
	for (int i = 0; i < 26; i++) {
		res += abs(cnta[i + 'a'] - cntb[i + 'a']);
	}
	cout << res << endl;
}

int main() {
    solve();
    return 0;
}

