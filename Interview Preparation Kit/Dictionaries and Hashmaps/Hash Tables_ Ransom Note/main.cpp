#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
	int n, m;
	cin >> n >> m;
	map<string, int> mag;
	while (n--) {
		string s;
		cin >> s;
		mag[s]++;
	}
	while (m--) {
		string s;
		cin >> s;
		if (mag.find(s) == mag.end() || mag[s] == 0) {
			cout << "No" << endl;
			return;
		}
		mag[s]--;
	}
	cout << "Yes" << endl;
}

int main() {
    solve();
    return 0;
}

