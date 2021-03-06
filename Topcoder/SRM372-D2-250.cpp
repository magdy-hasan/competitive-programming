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


class DietPlan {
public:
	string chooseDinner(string diet, string breakfast, string lunch);
};






int cnt[27];

string DietPlan::chooseDinner(string diet, string breakfast, string lunch) {
	for (int i = 0; i < 27; i++) cnt[i] = 0;
	for (char c : diet) cnt[c - 'A']++;
	for (char c : breakfast)
		if (cnt[c - 'A'] == 0) return "CHEATER";
		else cnt[c - 'A']--;
		for (char c : lunch) if (cnt[c - 'A'] == 0) return "CHEATER";
		else cnt[c - 'A']--;
		string ret;
		for (int i = 0; i < 27; i++) while (cnt[i] > 0)
			ret += (i + 'A'), cnt[i]--;
		return ret;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, string p0, string p1, string p2, bool hasAnswer, string p3) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << "\"" << p1 << "\"" << "," << "\"" << p2 << "\"";
	cout << "]" << endl;
	DietPlan *obj;
	string answer;
	obj = new DietPlan();
	clock_t startTime = clock();
	answer = obj->chooseDinner(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p3 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p3;
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

	string p0;
	string p1;
	string p2;
	string p3;

	{
		// ----- test 0 -----
		p0 = "ABCD";
		p1 = "AB";
		p2 = "C";
		p3 = "D";
		all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
		// ------------------
	}

	{
		// ----- test 1 -----
		p0 = "ABEDCS";
		p1 = "";
		p2 = "";
		p3 = "ABCDES";
		all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
		// ------------------
	}

	{
		// ----- test 2 -----
		p0 = "EDSMB";
		p1 = "MSD";
		p2 = "A";
		p3 = "CHEATER";
		all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
		// ------------------
	}

	{
		// ----- test 3 -----
		p0 = "";
		p1 = "";
		p2 = "";
		p3 = "";
		all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
		// ------------------
	}

	{
		// ----- test 4 -----
		p0 = "IWANTSODER";
		p1 = "SOW";
		p2 = "RAT";
		p3 = "DEIN";
		all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
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
