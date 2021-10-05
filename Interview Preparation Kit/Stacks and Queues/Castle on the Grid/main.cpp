#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 105;
const int inf = 100000;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
string grid[maxn];
int n, stx, sty, edx, edy;
int dis[maxn][maxn];

bool inside(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    cin >> stx >> sty >> edx >> edy;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dis[i][j] = inf;
        }
    }
    dis[stx][sty] = 0;
    queue<pair<int, int>> q;
    q.push({stx, sty});
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        // cout << cur.first << " " << cur.second << endl;
        if (cur.first == edx && cur.second == edy) {
            cout << dis[edx][edy] << endl;
            return;
        }
        for (int k = 0; k < 4; k++) {
            for (int x = cur.first + dx[k], y = cur.second + dy[k]; inside(x, y) && grid[x][y] == '.'; x += dx[k], y += dy[k]) {
                if (dis[x][y] == inf) {
                    dis[x][y] = dis[cur.first][cur.second] + 1;
                    q.push({x, y});
                }
            }
        }
    }
}

int main() {
    solve();
    return 0;
}

