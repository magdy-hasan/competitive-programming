/*
	obvious dp here, we have a mask of all points(2^15), 
	and then we  choose a set of points to make our convex polygon from ( maybe use convex hull )
	but this will TLE


	we can notice that if we make any convex polygon, by polygon traingluation
	we can always make it from triangles
	so problem is just to pick triangles from current set of points where we cover at least one new point
	our time is O(2^15*n^3) which is enough
*/
#include<bits/stdc++.h>
#include<complex>
using namespace std;

const double PI = acos(-1.0);

typedef complex<double> point;

#define lp(i, n)         for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)     for(int i=(j);i<(int)(n);++i)

const double EPS = 1e-10;
#define X real()
#define Y imag()
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel


int dcmp(double a, double b){
	return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1;
}

class PolygonCover {
public:
	double getArea(vector <int> xx, vector <int> yy);
};


double dp[(1 << 15)];
bool vis[(1 << 15)];
int n;
vector<point> ps;

double rec(int msk){
	if (msk + 1 == (1 << n)) return 0;
	double &ret = dp[msk];
	if (vis[msk]) return ret;
	vis[msk] = 1;
	ret = 123456789.;
	lp(i, n) lpi(j, i + 1, n) lpi(k, j + 1, n){
		if ((!(msk&(1 << i))) || (!(msk&(1 << j))) || (!(msk&(1 << k)))){
			double ar = fabs((cp(ps[i], ps[j]) + cp(ps[j], ps[k]) + cp(ps[k], ps[i])) / 2.0);
			ret = min(ret, rec(((msk | (1 << i)) | (1 << j)) | (1 << k)) + ar);
		}
	}
	return ret;
}

double PolygonCover::getArea(vector <int> xx, vector <int> yy) {
	n = xx.size();
	ps.clear();
	lp(i, (1 << (n + 1))) vis[i] = 0;
	lp(i, n) {
		ps.emplace_back(xx[i], yy[i]);
	}
	return rec(0);
}


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, bool hasAnswer, double p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}";
	cout << "]" << endl;
	PolygonCover *obj;
	double answer;
	obj = new PolygonCover();
	clock_t startTime = clock();
	answer = obj->getArea(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = fabs(p2 - answer) <= 1e-9 * max(1.0, fabs(p2));
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	}
	else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	}
	else if (hasAnswer) {
		cout << "Match :-)" << endl;
	}
	else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;

	vector <int> p0;
	vector <int> p1;
	double p2;

	{
		// ----- test 0 -----
		int t0[] = { 0, 10, 0, -10 };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		int t1[] = { -10, 0, 10, 0 };
		p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
		p2 = 200.0;
		all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 1 -----
		int t0[] = { -1, 2, -2, 0 };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		int t1[] = { -1, 0, 2, -1 };
		p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
		p2 = 2.0;
		all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 2 -----
		int t0[] = { 2, 0, -2, -1, 1, 0 };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		int t1[] = { 0, 2, 0, -2, -2, 1 };
		p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
		p2 = 3.0;
		all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 3 -----
		int t0[] = { 1, 0, -4, 0, 1, 4 };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		int t1[] = { 1, 4, 0, -4, -1, 0 };
		p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
		p2 = 6.0;
		all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
		// ------------------
	}

	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	}
	else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
