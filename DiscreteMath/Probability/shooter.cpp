#ifdef LOCAL
#include "task_selection.h"
#include "checker.h"
#else
#define shooter task
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

namespace shooter {

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

	double sum_prob;
	int n, k, m;
	double k_part;

	int main() {
		cin >> n >> m >> k;
		k--;
		for (auto i = 0; i < n; i++) {
			double prob;
			cin >> prob;
			prob = 1 - prob;
			double part = 1;
			for (auto j = 0; j < m; j++) {
				part *= prob;
			}
			sum_prob += part;
			if (i == k) {
				k_part = part;
			}
		}

		cout.precision(15);
		cout << fixed << k_part / sum_prob << endl;

		return 0;
	}
}

#if defined(shooter) && !defined(checker)
int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	while (!cin.eof()) {
		shooter::main();
	}
	shooter::wait();
#else   
	freopen("shooter.in ", "r", stdin);
	freopen("shooter.out", "w", stdout);
	shooter::main();
#endif
	return 0;
}
#endif