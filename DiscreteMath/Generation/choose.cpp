#ifdef LOCAL
#include "task_selection.h"
#include "checker.h"
#else
#define choose task
#endif

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <fstream>
#include <queue>
#include <stack>
#include <cassert>
#include <complex>
#include <bitset>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <list>

#include <forward_list>
#include <numeric>
#include <functional>
#include <initializer_list>

using namespace std;

namespace choose {

#if defined(_DEBUG)
#define debug printf
#define reader scanf
#define error(...) fprintf(stderr,__VA_ARGS__)

	void wait() {
		fclose(stdin);
		fclose(stdout);
		freopen("CON", "r", stdin);
		freopen("CON", "w", stdout);
		system("pause");
	}
#else
#define debug ;
#define reader ;
#define error ;
	void wait() {}
#endif

	typedef long long ll;
	typedef long double ld;
#define mp make_pair
#define write(a, c) for (auto i : a) cout << i << c;
#define all(a) (a).begin(), (a).end()

	const int K = 18;
	const ll MAXN = 1e6;
	const int INF = 2e9 + 1;
	const ll LONG_INF = 8e18;
	const ll MOD = 1e9 + 7;
	const ld e = 1e-9;
	const ll C = 500;
	const ll dx[4] = { -1, 0, 1, 0 };
	const ll dy[4] = { 0, 1, 0, -1 };

	vector< vector <int> > ans;
	vector<int> cur;
	bool use[MAXN];
	int n, k;

	void gena(int pos) {
		if (pos > n + 1) {
			return;
		}
		if (cur.size() == k) {
			ans.push_back(cur);
			return;
		}
		cur.push_back(pos);
		gena(pos + 1);
		cur.pop_back();
		gena(pos + 1);
	}

	int main() {
		cin >> n >> k;
		gena(1);

		for (auto& i : ans) {
			write(i, " ");
			cout << endl;
		}

		return 0;
	}
}

#if defined(choose) && !defined(checker)
int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	while (!cin.eof()) {
		choose::main();
	}
	choose::wait();
#else   
	freopen("choose.in ", "r", stdin);
	freopen("choose.out", "w", stdout);
	choose::main();
#endif
	return 0;
}
#endif