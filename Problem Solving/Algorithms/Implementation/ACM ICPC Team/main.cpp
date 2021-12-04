#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

int get_topic(string &a, string &b) {
    int sz = (int)a.size(), cnt = 0;
    for (int i = 0; i < sz; i++) {
        if (a[i] == '1' || b[i] == '1') cnt++;
    }
    return cnt;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> topic(n);
    for (auto &s : topic) {
        cin >> s;
    }
    int max_topic = 0, num_team = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int t = get_topic(topic[i], topic[j]);
            if (t > max_topic) {
                max_topic = t;
                num_team = 1;
            } else if (t == max_topic) {
                num_team++;
            }
        }
    }
    cout << max_topic << endl;
    cout << num_team << endl;
}

int main() {
    solve();
    return 0;
}

