#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    string str;
    cin >> str;
    vector<char> brackets;
    bool res = true;
    for (auto c: str) {
        if (c == ')' || c == '}' || c == ']') {
            if ((!brackets.empty())) {
                if (c == ')' && brackets.back() == '(' ||
                    c == ']' && brackets.back() == '[' ||
                    c == '}' && brackets.back() == '{') {
                    brackets.pop_back();
                } else {
                    res = false;
                    break;
                }
            } else {
                res = false;
                break;
            }
        } else {
            brackets.push_back(c);
        }
    }
    if (res && brackets.empty()) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

