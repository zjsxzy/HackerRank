#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 100005;
int n, m, x, y;
int vis[maxn];
vector<int> adj[maxn];

void dfs(int u) {
    vis[u] = true;
    for (auto& v: adj[u]) {
        if (!vis[v]) dfs(v);
    }
}

void solve() {
    cin >> n >> m >> x >> y;
    for (int i = 0; i < n; i++) {
        adj[i].clear();
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].PB(v);
        adj[v].PB(u);
    }
    memset(vis, false, sizeof(vis));
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i);
            cnt++;
        }
    }
    LL res = (LL)cnt * x;
    res += (LL)((x < y) ? x : y) * (n - cnt);
    cout << res << endl;
}

int main() {
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

