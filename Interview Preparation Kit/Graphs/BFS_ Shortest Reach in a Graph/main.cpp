#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int inf = 1e9;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].PB(v);
        adj[v].PB(u);
    }
    int st;
    cin >> st;
    st--;

    vector<int> dist(n, inf);
    dist[st] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, st});
    while (!pq.empty()) {
        auto p = pq.top(); pq.pop();
        int u = p.second;
        if (p.first > dist[u]) continue;
        for (auto& v: adj[u]) {
            int nd = p.first + 6;
            if (nd < dist[v]) {
                dist[v] = nd;
                pq.push({nd, v});
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (i == st) continue;
        if (dist[i] == inf) cout << -1 << " ";
        else cout << dist[i] << " ";
    }
    cout << endl;
}

int main() {
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

