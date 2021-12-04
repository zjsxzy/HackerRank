#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int k;
	cin >> k;
	for (auto &c : s) {
		if (c >= 'a' && c <= 'z') {
			c = ((c - 'a' + k) % 26) + 'a';
		} else if (c >= 'A' && c <= 'Z') {
			c = ((c - 'A' + k) % 26) + 'A';
		}
	}
	cout << s << endl;
}

int main() {
    solve();
    return 0;
}

