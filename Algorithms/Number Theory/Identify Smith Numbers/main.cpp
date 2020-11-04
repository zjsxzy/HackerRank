#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
#include <climits>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

int sum_dig(int n) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int sum_prime(int n) {
    vector<int> prime;
    vector<bool> vis((int)sqrt(n) + 1);
    for (int i = 2; i <= (int)sqrt(n); i++) {
        if (!vis[i]) {
            prime.push_back(i);
            for (int j = 1; i * j <= (int)sqrt(n); j++) {
                vis[i * j] = true;
            }
        }
    }
    int sum = 0;
    for (auto x : prime) {
        while (n % x == 0) {
            sum += sum_dig(x);
            n /= x;
        }
    }
    if (n > 1) {
        sum += sum_dig(n);
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    if (sum_dig(n) == sum_prime(n)) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}