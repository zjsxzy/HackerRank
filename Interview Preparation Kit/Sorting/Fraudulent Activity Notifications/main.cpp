#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n, d;
    cin >> n >> d;
    vector<int> arr(n), cnt(201);
    for (auto &x: arr) {
        cin >> x;
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (i < d) {
            cnt[arr[i]]++;
        } else {
            // calculate median
            int median_mul_2 = 0, tot = 0;
            for (int x = 0; x <= 200; x++) {
                if (cnt[x] > 0) {
                    tot += cnt[x];
                    if (tot >= d / 2) {
                        if (d % 2 == 1) {
                            if (tot > d / 2) {
                                median_mul_2 = x * 2;
                                break;
                            }
                        } else {
                            if (tot == d / 2) {
                            median_mul_2 += x;
                            } else {
                                if (median_mul_2 == 0) median_mul_2 = 2 * x;
                                else median_mul_2 += x;
                                break;
                            }
                        }
                    }
                }
            }
            // cout << i << " " << arr[i] << " " << median_mul_2 << endl;
            if (arr[i] >= median_mul_2) {
                res++;
            }
            cnt[arr[i]]++;
            cnt[arr[i - d]]--;
        }
    }
    cout << res << endl;
}

int main() {
    solve();
    return 0;
}

