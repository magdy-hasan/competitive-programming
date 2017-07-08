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


class AlienAndGame {
public:
	int getNumber(vector <string> board);
};

int AlienAndGame::getNumber(vector <string> board) {
	int n = board.size(), m = board[0].size();
	int ret = -1;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++){
		int mxln = 123456789;
		for (int k = i; k < n; k++){
			if (board[k][j] == 'W'){
				int p = j;
				for (; p < m; p++) if (board[k][p] != 'W') break;
				mxln = min(mxln, p - j);
			}
			else{
				int p = j;
				for (; p < m; p++) if (board[k][p] != 'B') break;
				mxln = min(mxln, p - j);
			}
			int side = min(mxln, (k - i + 1));
			ret = max(ret, side*side);
		}
	}
	return ret;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	AlienAndGame *obj;
	int answer;
	obj = new AlienAndGame();
	clock_t startTime = clock();
	answer = obj->getNumber(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
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

	vector <string> p0;
	int p1;

	{
		// ----- test 0 -----
		string t0[] = { "BB", "WW" };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 4;
		all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 1 -----
		string t0[] = { "W" };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 1;
		all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 2 -----
		string t0[] = { "WBBB", "WBBB", "WWWW" };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 9;
		all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 3 -----
		string t0[] = { "W", "B", "W", "W", "W" };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 1;
		all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 4 -----
		string t0[] = { "BWBBWBB", "WWBWWBW", "BBBBBBW", "WBBBBWB", "BBWWWWB", "WWWWWWW", "BBWWBBB" };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 9;
		all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
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
