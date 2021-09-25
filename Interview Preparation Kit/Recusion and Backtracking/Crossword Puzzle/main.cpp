#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

bool flag;
vector<string> words, grid(10);

void dfs(int idx) {
    if (flag) return;
    if (idx == words.size()) {
        for (auto w: grid) {
            cout << w << endl;
        }
        flag = true;
        return;
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int k;
            for (k = 0; k < words[idx].size() && i + k < 10; k++) {
                if (grid[i + k][j] != '-' && grid[i + k][j] != words[idx][k]) {
                    break;
                }
            }
            if (k == words[idx].size()) {
                vector<string> temp = grid;
                for (int k = 0; k < words[idx].size(); k++) {
                    grid[i + k][j] = words[idx][k];
                }
                dfs(idx + 1);
                grid = temp;
            }

            for (k = 0; k < words[idx].size() && j + k < 10; k++) {
                if (grid[i][j + k] != '-' && grid[i][j + k] != words[idx][k]) {
                    break;
                }
            }
            if (k == words[idx].size()) {
                vector<string> temp = grid;
                for (int k = 0; k < words[idx].size(); k++) {
                    grid[i][j + k] = words[idx][k];
                }
                dfs(idx + 1);
                grid = temp;
            }
        }
    }
}

void solve() {
    for (int i = 0; i < 10; i++) {
        cin >> grid[i];
    }
    string w, s;
    cin >> w;
    for (auto c: w) {
        if (c == ';') {
            words.PB(s);
            s = "";
        } else {
            s += c;
        }
    }
    words.PB(s);
    dfs(0);
}

int main() {
    solve();
    return 0;
}

