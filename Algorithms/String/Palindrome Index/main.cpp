#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

bool palindrome(string s) {
    int n = SZ(s);
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i]) return false;
    }
    return true;
}

void solve() {
    string str;
    cin >> str;
    if (palindrome(str)) {
        cout << -1 << endl;
        return;
    }
    int n = SZ(str);
    int l = 0, r = n - 1;
    while (l < r && str[l] == str[r]) {
        l++; r--;
    }
    string s = str;
    s.erase(l, 1);
    if (palindrome(s)) {
        cout << l << endl;
        return;
    }
    str.erase(r, 1);
    if (palindrome(str)) {
        cout << r << endl;
        return;
    }
    cout << -1 << endl;
}

int main() {
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

