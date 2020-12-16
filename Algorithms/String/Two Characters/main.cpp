#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
	int n;
	string s;
	cin >> n >> s;
	map<char, int> cnt;
	for (auto &c : s) {
		cnt[c]++;
	}
	int res = 0;
	for (int i = 0; i < 26; i++) {
		for (int j = i + 1; j < 26; j++) {
			char a = 'a' + i, b = 'a' + j;
			if (cnt[a] > 0 && cnt[b] > 0) {
				string t;
				for (auto &c : s) {
					if (c == a || c == b) t += c;
				}
				bool valid = true;
				for (int i = 1; i < SZ(t); i++) {
					if (t[i] == t[i - 1]) {
						valid = false;
						break;
					}
				}
				if (valid) res = max(res, SZ(t));
			}
		}
	}
	cout << res << endl;
}

int main() {
    solve();
    return 0;
}

