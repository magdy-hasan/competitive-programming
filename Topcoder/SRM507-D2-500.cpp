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


class CubeStickers {
public:
	string isPossible(vector <string> sticker);
};

vector<string> s;

bool rec(int idx, vector<int> cur){
	if (cur.size() == 6){
		sort(cur.begin(), cur.end());
		do{
			bool f = 1;
			for (int j = 1; j < 5; j++) f &= (s[cur[0]] != s[cur[j]]) && (s[cur[5]] != s[cur[j]]);
			f &= s[cur[2]] != s[cur[1]] && s[cur[3]] != s[cur[1]];
			for (int j = 0; j < 6; j++) if (j != 1 && j != 4) f &= s[cur[j]] != s[cur[4]];
			if (f) return 1;
		} while (next_permutation(cur.begin() + 1, cur.end()));
		return 0;
	}
	if (idx >= s.size()) return 0;
	if (rec(idx + 1, cur)) return 1;
	cur.push_back(idx);
	return rec(idx + 1, cur);
}

map<string, int> cnt;

string CubeStickers::isPossible(vector <string> sticker) {
	s.clear();
	cnt.clear();
	for (string ss : sticker)
		if (cnt.find(ss) == cnt.end()) cnt[ss] = 1, s.push_back(ss);
		else if (cnt[ss] < 4) cnt[ss]++, s.push_back(ss);
		else;
		return rec(0, {}) ? "YES" : "NO";
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	CubeStickers *obj;
	string answer;
	obj = new CubeStickers();
	clock_t startTime = clock();
	answer = obj->isPossible(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p1 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
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
	string p1;

	{
		// ----- test 0 -----
		string t0[] = { "cyan", "magenta", "yellow", "purple", "black", "white", "purple" };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = "YES";
		all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 1 -----
		string t0[] = { "blue", "blue", "blue", "blue", "blue", "blue", "blue", "blue", "blue", "blue" };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = "NO";
		all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 2 -----
		string t0[] = { "red", "yellow", "blue", "red", "yellow", "blue", "red", "yellow", "blue" };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = "YES";
		all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 3 -----
		string t0[] = { "purple", "orange", "orange", "purple", "black", "orange", "purple" };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = "NO";
		all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 4 -----
		string t0[] = { "white", "gray", "green", "blue", "yellow", "red", "target", "admin" };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = "YES";
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
