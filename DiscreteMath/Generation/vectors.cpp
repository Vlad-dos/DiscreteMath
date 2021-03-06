#ifdef LOCAL
#include "task_selection.h"
#include "checker.h"
#else
#define vectors task
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

namespace vectors {

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

	typedef long long T;
	typedef long double ld;
#define mp make_pair
#define write(a, c) for (auto& i : a) cout << i << c;
#define all(a) (a).begin(), (a).end()

	const int K = 18;
	const T MAXN = 1e6;
	const int INF = 2e9 + 1;
	const T LONG_INF = 8e18;
	const T MOD = 1e9 + 7;
	const ld e = 1e-9;
	const T C = 500;
	const T dx[4] = { -1, 0, 1, 0 };
	const T dy[4] = { 0, 1, 0, -1 };

	vector< vector <int> > ans;
	vector<int> cur;
	int n;

	void gena() {
		if (cur.size() == n) {
			ans.push_back(cur);
			return;
		}
		if (cur.size() > 0 && cur.back() == 1) {
			cur.push_back(0);
			gena();
			cur.pop_back();
		}
		else {
			cur.push_back(0);
			gena();
			cur.pop_back();
			cur.push_back(1);
			gena();
			cur.pop_back();
		}
	}

	int main() {
		cin >> n;
		gena();

		cout << ans.size() << endl;
		for (auto& i : ans) {
			write(i, "");
			cout << endl;
		}

		return 0;
	}
}

#if defined(vectors) && !defined(checker)
int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	while (!cin.eof()) {
		vectors::main();
	}
	vectors::wait();
#else   
	freopen("vectors.in ", "r", stdin);
	freopen("vectors.out", "w", stdout);
	vectors::main();
#endif
	return 0;
}
#endif