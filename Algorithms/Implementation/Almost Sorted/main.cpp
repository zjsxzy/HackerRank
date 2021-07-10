#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), sorted(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sorted[i] = a[i];
    }
    sort(sorted.begin(), sorted.end());
    vector<int> pos;
    for (int i = 0; i < n; i++) {
        if (sorted[i] != a[i]) {
            pos.push_back(i);
        }
    }
    if (pos.size() == 0) {
        cout << "yes" << endl;
        return;
    }
    if (pos.size() == 2) {
        cout << "yes" << endl;
        cout << "swap " << pos[0] + 1 << " " << pos[1] + 1 << endl;
        return;
    }
    int l = pos[0], r = pos[pos.size() - 1];
    while (l < r) {
        swap(a[l], a[r]);
        l++;
        r--;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] != sorted[i]) {
            cout << "no" << endl;
            return;
        }
    }
    cout << "yes" << endl;
    cout << "reverse " << pos[0] + 1 << " " << pos[pos.size() - 1] + 1 << endl;
}

int main() {
    solve();
    return 0;
}

