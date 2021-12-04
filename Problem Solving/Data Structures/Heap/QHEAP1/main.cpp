#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int q;
    cin >> q;
    multiset<int> heap;
    while (q--) {
        int type, x;
        cin >> type;
        if (type == 1 || type == 2) {
            cin >> x;
            if (type == 1) heap.insert(x);
            else heap.erase(x);
        } else {
            cout << *heap.begin() << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}

