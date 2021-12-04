#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int mod = 1e9 + 7;
void solve() {
	string s;
	cin >> s;
	int n = s.size();
	vector<vector<LL>> f(26, vector<LL>(26, 0));
	vector<int> prefix(26), suffix(26);
	for (char &c: s) {
		suffix[c - 'a']++;
	}
	LL res = 0;
	for (auto &c: s) {
		suffix[c - 'a']--;
		for (int i = 0; i < 26; i++) {
			res += (LL)f[i][c - 'a'] * suffix[i];
			res %= mod;
		}
		for (int i = 0; i < 26; i++) {
			f[i][c - 'a'] += prefix[i];
		}
		prefix[c - 'a']++;
	}
	cout << res << endl;
}

int main() {
    solve();
    return 0;
}

