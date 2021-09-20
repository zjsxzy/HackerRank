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
    for (auto &x: arr) {
        cin >> x;
    }
    reverse(arr.begin(), arr.end());
    for (auto &x: arr) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    solve();
    return 0;
}

