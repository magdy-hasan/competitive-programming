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


class WordFind {
public:
	vector <string> findWords(vector <string> grid, vector <string> wordList);
};


int n, m;
string word;
vector <string> g;
bool vis[55][55];

int di[] = { 1, 1, 0 };
int dj[] = { 0, 1, 1 };

bool dfs(int i, int j, int idx, int k){
	if (idx == word.size()) return 1;
	if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || g[i][j] != word[idx]) return 0;
	vis[i][j] = 1;
	if (dfs(i + di[k], j + dj[k], idx + 1, k))
		return 1;
	return 0;
}

vector <string> WordFind::findWords(vector <string> grid, vector <string> w) {
	g = grid;
	n = g.size(), m = g[0].size();
	vector <string> ret;
	for (int iw = 0; iw < w.size(); iw++){
		int r = -1, c = -1;
		for (int i = 0; i < n && (r == -1); i++)  for (int j = 0; j < m && (r == -1); j++)  if (g[i][j] == w[iw][0]){
			word = w[iw];
			bool ff = 0;
			for (int k = 0; k < 3; k++) {
				for (int i1 = 0; i1 < n; i1++) for (int j1 = 0; j1 < m; j1++) vis[i1][j1] = 0;
				ff |= dfs(i, j, 0, k);
				if (ff) break;
			}
			if (ff){
				r = i, c = j;
				break;
			}
		}
		if (r != -1)  ret.push_back(to_string(r) + " " + to_string(c));
		else ret.push_back("");
	}
	return ret;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, vector <string> p1, bool hasAnswer, vector <string> p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p1[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	WordFind *obj;
	vector <string> answer;
	obj = new WordFind();
	clock_t startTime = clock();
	answer = obj->findWords(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p2.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << "\"" << p2[i] << "\"";
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "{";
	for (int i = 0; int(answer.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << answer[i] << "\"";
	}
	cout << "}" << endl;
	if (hasAnswer) {
		if (answer.size() != p2.size()) {
			res = false;
		}
		else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p2[i]) {
					res = false;
				}
			}
		}
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
	vector <string> p1;
	vector <string> p2;

	{
		// ----- test 0 -----
		string t0[] = { "TEST", "GOAT", "BOAT" };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		string t1[] = { "GOAT", "BOAT", "TEST" };
		p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
		string t2[] = { "1 0", "2 0", "0 0" };
		p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
		all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 1 -----
		string t0[] = { "SXXX", "XQXM", "XXLA", "XXXR" };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		string t1[] = { "SQL", "RAM" };
		p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
		string t2[] = { "0 0", "" };
		p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
		all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 2 -----
		string t0[] = { "EASYTOFINDEAGSRVHOTCJYG", "FLVENKDHCESOXXXXFAGJKEO", "YHEDYNAIRQGIZECGXQLKDBI", "DEIJFKABAQSIHSNDLOMYJIN", "CKXINIMMNGRNSNRGIWQLWOG", "VOFQDROQGCWDKOUYRAFUCDO", "PFLXWTYKOITSURQJGEGSPGG" };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		string t1[] = { "EASYTOFIND", "DIAG", "GOING", "THISISTOOLONGTOFITINTHISPUZZLE" };
		p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
		string t2[] = { "0 0", "1 6", "0 22", "" };
		p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
		all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
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
