#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int q;
    cin >> q;
    map<int, int> cnt, freq;
    for (int i = 0; i < q; i++) {
        int type, val;
        cin >> type >> val;
        if (type == 1) {
            if (freq[cnt[val]] > 0) freq[cnt[val]]--;
            cnt[val]++;
            freq[cnt[val]]++;
        } else if (type == 2) {
            if (freq[cnt[val]] > 0) freq[cnt[val]]--;
            if (cnt[val] > 0) cnt[val]--;
            freq[cnt[val]]++;
        } else {
            cout << (freq[val] > 0 ? 1 : 0) << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}

