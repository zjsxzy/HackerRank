#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
	int n;
	cin >> n;
	vector<int> cnt(100);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cnt[x]++;
	}
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < cnt[i]; j++) {
			cout << i << " ";
		}
	}
	cout << endl;
}

int main() {
    solve();
    return 0;
}

