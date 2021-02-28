#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int r, c, n;

void output(vector<vector<int>> &bomb) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (bomb[i][j]) cout << 'O';
            else cout << ".";
        }
        cout << endl;
    }
}

bool inside(int i, int j) {
    return (i >= 0 && i < r && j >= 0 && j < c);
}

void solve() {
    cin >> r >> c >> n;
    vector<vector<int>> bomb(r, vector<int>(c, 0));
    for (int i = 0; i < r; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < c; j++) {
            bomb[i][j] = str[j] == 'O';
        }
    }

    if (n == 1) {
        output(bomb);
        return;
    }
    if (n % 2 == 0) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                bomb[i][j] = true;
            }
        }
        output(bomb);
        return;
    }
    vector<vector<int>> next = bomb;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            for (int k = 0; k < 4; k++) {
                if (inside(i + dx[k], j + dy[k])) {
                    next[i + dx[k]][j + dy[k]] |= bomb[i][j];
                }
            }
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            bomb[i][j] = 1 ^ next[i][j];
        }
    }
    if (n % 4 == 3) {
        output(bomb);
        return;
    }
    next = bomb;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            for (int k = 0; k < 4; k++) {
                if (inside(i + dx[k], j + dy[k])) {
                    next[i + dx[k]][j + dy[k]] |= bomb[i][j];
                }
            }
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            bomb[i][j] = 1 ^ next[i][j];
        }
    }
    output(bomb);
}

int main() {
    solve();
    return 0;
}

