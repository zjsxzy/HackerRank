#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 5;
const int maxm = 5;
const int mod = 1e9 + 7;
struct Matrix {
	int n, m;
	LL mat[maxn][maxm];

	void init() {
		n = m = 0;
		memset(mat, 0, sizeof(mat));
	}
	Matrix operator + (const Matrix &b) const {
		Matrix tmp;
		tmp.n = n; tmp.m = m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				tmp.mat[i][j] = mat[i][j] + b.mat[i][j];
			}
		}
		return tmp;
	}
	Matrix operator - (const Matrix &b) const {
		Matrix tmp;
		tmp.n = n; tmp.m = m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				tmp.mat[i][j] = mat[i][j] - b.mat[i][j];
			}
		}
		return tmp;
	}
	Matrix operator * (const Matrix &b) const {
		Matrix tmp;
		tmp.init();
		tmp.n = n; tmp.m = b.m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < b.m; j++) {
				for (int k = 0; k < m; k++) {
					tmp.mat[i][j] = (tmp.mat[i][j] + mat[i][k] * b.mat[k][j]) % mod;
				}
			}
		}
		return tmp;
	}
	Matrix operator ^ (int x) {
		Matrix res, p = *this;
		res.init();
		res.n = res.m = n;
		for (int i = 0; i < n; i++)
			res.mat[i][i] = 1;
		for (; x; x >>= 1) {
			if (x & 1) res = res * p;
			p = p * p;
		}
		return res;
	}
	void output() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}
	}
};

void solve() {
    int a, b, n;
    cin >> a >> b >> n;
    Matrix A;
    A.init();
    A.n = A.m = 2;
    A.mat[0][0] = 0; A.mat[0][1] = 1;
    A.mat[1][0] = 1; A.mat[1][1] = 1;
    Matrix F;
    F.init();
    F.n = 2; F.m = 1;
    F.mat[0][0] = a; F.mat[1][0] = b;
    Matrix res = A ^ n;
    res = res * F;
    // res.output();
    cout << res.mat[0][0] << endl;
}

int main() {
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

