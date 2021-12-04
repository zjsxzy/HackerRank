#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    string str, s;
    while (cin >> s) {
        str += s;
    }
    vector<int> cnt(26);
    for (char &c : str) {
        c = tolower(c);
        cnt[c - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (cnt[i] == 0) {
            cout << "not pangram" << endl;
            return;
        }
    }
    cout << "pangram" << endl;
}

int main() {
    solve();
    return 0;
}

