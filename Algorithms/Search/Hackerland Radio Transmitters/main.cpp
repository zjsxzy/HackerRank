#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 100005;
int n, k;
int x[maxn];

void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	sort(x, x + n);
	int res = 0;
	for (int i = 0; i < n; ) {
		res++;
		int first = x[i];
		while (i < n && (x[i] - first) <= k) {
			i++;
		}
		int transmitter = x[i - 1];
		while (i < n && (x[i] - transmitter) <= k) {
			i++;
		}
	}
	cout << res << endl;
}

int main() {
    solve();
    return 0;
}

