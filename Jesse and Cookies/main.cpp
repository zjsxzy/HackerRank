#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
	int n, k;
	cin >> n >> k;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		pq.push(x);
	}
	int res = 0;
	while (!pq.empty()) {
		int first = pq.top(); pq.pop();
		if (first >= k) break;
		if (pq.empty()) {
			cout << -1 << endl;
			return;
		}
		int second = pq.top(); pq.pop();
		int t = first + 2 * second;
		res++;
		pq.push(t);
	}
	cout << res << endl;

}

int main() {
    solve();
    return 0;
}

