#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int lena, lenb, lenc;
    cin >> lena >> lenb >> lenc;
    vector<int> a(lena), b(lenb), c(lenc);
    for (auto &x: a) {
        cin >> x;
    }
    for (auto &x: b) {
        cin >> x;
    }
    for (auto &x: c) {
        cin >> x;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    c.erase(unique(c.begin(), c.end()), c.end());

    int i = 0, j = 0, k = 0;
    LL res = 0;
    while (j < b.size()) {
        while (a[i] <= b[j] && i < a.size()) {
            i++;
        }
        while (c[k] <= b[j] && k < c.size()) {
            k++;
        }
        res += (LL)i * k;
        j++;
    }
    cout << res << endl;
}

int main() {
    solve();
    return 0;
}

