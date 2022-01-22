#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto& x: arr) cin >> x;
    vector<int> left(n, -1); // index to the next element < a[i] on the left.
    vector<int> right(n, n); // index to the next element < a[i] on the right.
    stack<int> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        if (!s.empty()) {
            left[i] = s.top();
        }
        s.push(i);
    }
    while (!s.empty()) s.pop();
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        if (!s.empty()) {
            right[i] = s.top();
        }
        s.push(i);
    }

    vector<int> ans(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int window = (right[i] - 1) - (left[i] + 1) + 1;
        ans[window] = max(ans[window], arr[i]);
    }
    for (int window = n - 1; window >= 1; window--) {
        ans[window] = max(ans[window], ans[window + 1]);
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    solve();
    return 0;
}

