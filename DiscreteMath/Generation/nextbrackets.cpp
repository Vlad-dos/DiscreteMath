#ifdef LOCAL
#include "task_selection.h"
#include "checker.h"
#else
#define nextbrackets task
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

namespace nextbrackets {

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

	string s;

	void gena() {
		int close = 0;
		int open = 0;
		for (int i = s.size() - 1; i >= 0; i--) {
			if (s[i] == '(') {
				open++;
				if (close > open) {
					break;
				}
			}
			else {
				close++;
			}
		}
		s.erase(s.end() - open - close, s.end());
		if (s == "")
			s = "-";
		else {
			s += ')';
			for (int i = 0; i < open; i++)
				s += '(';
			for (int j = 0; j < close - 1; j++)
				s += ')';
		}
	}

	int main() {
		cin >> s;
		gena();
		cout << s;

		return 0;
	}
}

#if defined(nextbrackets) && !defined(checker)
int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	while (!cin.eof()) {
		nextbrackets::main();
	}
	nextbrackets::wait();
#else   
	freopen("nextbrackets.in ", "r", stdin);
	freopen("nextbrackets.out", "w", stdout);
	nextbrackets::main();
#endif
	return 0;
}
#endif