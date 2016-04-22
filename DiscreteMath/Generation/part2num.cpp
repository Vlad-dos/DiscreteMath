#ifdef LOCAL
#include "task_selection.h"
#include "checker.h"
#else
#define part2num task
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

namespace part2num {

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
	const ll MAXN = 300;
	const int INF = 2e9 + 1;
	const ll LONG_INF = 8e18;
	const ll MOD = 1e9 + 7;
	const ld e = 1e-9;
	const ll C = 500;
	const ll dx[4] = { -1, 0, 1, 0 };
	const ll dy[4] = { 0, 1, 0, -1 };

	ll n, k;
	ll parts[MAXN][MAXN];

	int main() {
		string s;
		cin >> s;
		vector<ll>part;
		
		string number;
		for (char a : s) {
			if (a == '+') {
				part.push_back(atoi(number.c_str()));
				number.clear();
			}
			else {
				number += a;
			}
		}
		part.push_back(atoi(number.c_str()));
		n = accumulate(part.begin(), part.end(), 0);

		for (ll i = 0; i <= n; i++) {
			for (ll j = n; j >= 0; j--) {
				if (i == 0) {
					parts[i][j] = 1;
				}
				else if (j == i) {
					parts[i][j] = 1;
				}
				else if (j > i) {
					parts[i][j] = 0;
				}
				else {
					parts[i][j] = parts[i][j + 1] + parts[i - j][j];
				}
			}
		}

		ll pos = 1;
		for (auto i : part) {
			for (int j = pos; j < i; j++) {
				k += parts[n - j][j];
			}
			n -= i;
			pos = i;
		}

		cout << k << endl;

		return 0;
	}
}

#if defined(part2num) && !defined(checker)
int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	while (!cin.eof()) {
		part2num::main();
	}
	part2num::wait();
#else   
	freopen("part2num.in ", "r", stdin);
	freopen("part2num.out", "w", stdout);
	part2num::main();
#endif
	return 0;
}
#endif