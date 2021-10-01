#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<LL> heights(n);
    for (auto& x: heights) {
        cin >> x;
    }
    stack<int> stk;
    vector<int> left(n), right(n);
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && heights[stk.top()] >= heights[i]) {
            stk.pop();
        }
        left[i] = (stk.empty() ? -1 : stk.top());
        stk.push(i);
    }
    for (int i = 0; i < n; i++) {
        cout << i << " " << left[i] << endl;
    }
    stk = stack<int>();
    for (int i = n - 1; i >= 0; i--) {
        while (!stk.empty() && heights[stk.top()] >= heights[i]) {
            stk.pop();
        }
        right[i] = (stk.empty() ? n : stk.top());
        stk.push(i);
    }
    LL res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, heights[i] * (right[i] - left[i] - 1));
    }
    cout << res << endl;
}

int main() {
    solve();
    return 0;
}

