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

const double eps = 1E-8;
int sig(double d) {
	return (d>eps) - (d<-eps);
}
struct Point {
	double x, y, z;
	Point(double x, double y, double z) : x(x), y(y), z(z) {}
	Point() {}
	Point operator + (const Point & p) const {
		return Point(x+p.x, y+p.y, z+p.z);
	}
	Point operator - (const Point & p) const {
		return Point(x-p.x, y-p.y, z-p.z);
	}
	Point operator * (const double & d) const {
		return Point(x*d, y*d, z*d);
	}
	Point resize(double d) {
		d /= sqrt(x*x+y*y+z*z);
		return Point(x*d, y*d, z*d);
	}
	double len() const {
		return sqrt(x*x+y*y+z*z);
	}
	bool operator < (const Point & p) const {
		return sig(x-p.x)!=0 ? x<p.x : sig(y-p.y)!=0 ? y<p.y : sig(z-p.z)<0;
	}
	bool operator == (const Point & p) const {
		return sig(x-p.x)==0 && sig(y-p.y)==0 && sig(z-p.z)==0;
	}
	void input() {
		scanf("%lf%lf%lf", &x, &y, &z);
	}
	void output() const {
		printf("x = %.2f, y = %.2f, z = %.2f\n", x, y, z);
	}
};
//点乘
double dot(const Point & a, const Point & b) {
	return a.x*b.x + a.y*b.y + a.z*b.z;
}
double max(double a, double b) {
	return a < b ? b : a;
}

int main() {
	int ts;
	scanf("%d", &ts);
	for (int cas = 1; cas <= ts; cas++) {
		double r1, r2;
		Point p1, p2, v1, v2;
		scanf("%lf%lf", &r1, &r2);
		p1.input(); v1.input();
		p2.input(); v2.input();
		Point p = p1 - p2;
		Point v = v1 - v2;
		double calc = -dot(v, p) / dot(v, v);
		double t = max(calc, 0);
		Point temp = p + (v * t);
		if (sig(temp.len() * temp.len() - (r1 + r2) * (r1 + r2)) <= 0) {
			puts("YES");
		} else {
			puts("NO");
		}
	}
	return 0;
}

