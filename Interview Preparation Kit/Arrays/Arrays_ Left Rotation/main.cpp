#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long ll;

void solve() {
    int n, d;
    cin >> n >> d;
    vector<int> arr(n);
    for (auto &x: arr) {
        cin >> x;
    }
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        res[(i - d + n) % n] = arr[i];
    }
    for (auto &x: res) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    solve();
    return 0;
}

