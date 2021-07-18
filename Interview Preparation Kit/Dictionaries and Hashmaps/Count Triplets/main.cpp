#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n, r;
    cin >> n >> r;
    vector<int> arr(n);
    map<int, int> cnt;
    for (auto &x: arr) {
        cin >> x;
        cnt[x]++;
    }
    long long res = 0;
    if (r == 1) {
        for (auto &[k, v]: cnt) {
            if (v >= 3) {
                res += (LL)v * (v - 1) * (v - 2) / 6;
            }
        }
        cout << res << endl;
        return;
    }
    map<int, int> left;
    for (int i = 0; i < n; i++) {
        long long y = arr[i];
        if (y % r == 0) {
            long long x = (LL)arr[i] / r, z = arr[i] * r;
            if (left.find(x) != left.end() && cnt.find(z) != cnt.end()) {
                res += (LL)left[x] * cnt[z];
            }
        }
        left[arr[i]]++;
        cnt[arr[i]]--;
    }
    cout << res << endl;
}

int main() {
    solve();
    return 0;
}

