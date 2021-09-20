#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 1000005;
const int inf = 1e7;
int n, m, color;
vector<int> adj[maxn];
vector<int> ids, dist;

int dijkstra(int st) {
    dist[st] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, st});
    while (!pq.empty()) {
        auto p = pq.top(); pq.pop();
        int u = p.second;
        if (p.first > dist[u]) continue;
        for (auto &v: adj[u]) {
            int nd = p.first + 1;
            if (nd < dist[v]) {
                dist[v] = nd;
                pq.push({nd, v});
            }
        }
    }
    int ans = inf;
    for (int i = 0; i < n; i++) {
        if (i == st) continue;
        if (ids[i] == color && dist[i] < ans) {
            ans = dist[i];
        }
    }
    return ans;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ids.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> ids[i];
    }
    cin >> color;

    int res = inf;
    dist.resize(n);
    for (int i = 0; i < n; i++) {
        dist[i] = inf;
    }
    for (int i = 0; i < n; i++) {
        if (ids[i] == color && dist[i] == inf) {
            int d = dijkstra(i);
            if (d < res) res = d;
        }
    }
    if (res == inf) cout << -1 << endl;
    else cout << res << endl;
}

int main() {
    solve();
    return 0;
}

