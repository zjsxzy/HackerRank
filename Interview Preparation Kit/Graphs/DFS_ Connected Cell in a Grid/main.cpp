#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 15;
int dx[8] = {0, 0, -1, 1, 1, 1, -1, -1};
int dy[8] = {-1, 1, 0, 0, -1, 1, 1, -1};
int n, m, cnt;
int grid[maxn][maxn], vis[maxn][maxn];

bool inside(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int i, int j) {
    vis[i][j] = true;
    if (grid[i][j] == 1) cnt++;
    else return;
    for (int k = 0; k < 8; k++) {
        int x = i + dx[k], y = j + dy[k];
        if (inside(x, y) && !vis[x][y]) {
            dfs(x, y);
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j]) {
                cnt = 0;
                dfs(i, j);
                res = max(res, cnt);
            }
        }
    }
    cout << res << endl;
}

int main() {
    solve();
    return 0;
}

