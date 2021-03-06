#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class BouncingBalls {
public:
	double expectedBounces(vector <int> x, int T);
};

double BouncingBalls::expectedBounces(vector <int> x, int T) {
	int n = x.size(), coll = 0;
	sort(x.begin(), x.end());
	for (int msk = 0; msk < (1 << n); msk++){
		for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++)
			if (!(msk&(1 << i)) && (msk&(1 << j)) && x[j] - x[i] <= 2 * T)
				coll++;
	}
	return coll / double(1 << n);
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, int p1, bool hasAnswer, double p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << p1;
	cout << "]" << endl;
	BouncingBalls *obj;
	double answer;
	obj = new BouncingBalls();
	clock_t startTime = clock();
	answer = obj->expectedBounces(p0, p1);
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
		res = answer == answer && fabs(p2 - answer) <= 1e-9 * max(1.0, fabs(p2));
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
	int p1;
	double p2;

	{
		// ----- test 0 -----
		int t0[] = { 5, 8 };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 2;
		p2 = 0.25;
		all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 1 -----
		int t0[] = { 5, 8 };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 1;
		p2 = 0.0;
		all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 2 -----
		int t0[] = { 91, 857, 692, 54, 8679, 83, 792, 86, 9537, 913, 64, 592 };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 458;
		p2 = 11.5;
		all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 3 -----
		int t0[] = { 75432 };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 386;
		p2 = 0.0;
		all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 4 -----
		int t0[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 3;
		p2 = 12.75;
		all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
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


//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
