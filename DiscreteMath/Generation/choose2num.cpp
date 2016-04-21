#ifdef LOCAL
#include "task_selection.h"
#include "checker.h"
#else
#define choose2num task
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

namespace choose2num {

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

	ll n, m, k;
	int use[MAXN];
	ll choose[MAXN][MAXN];

	int main() {
		cin >> n >> k;
		choose[0][0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				choose[i][j] = choose[i - 1][j] + (j > 0 ? choose[i - 1][j - 1] : 0);
			}
		}

		for (int i = 0; i < k; i++) {
			int x;
			cin >> x;
			use[x - 1] = 1;
		}

		m = 0;
		ll cnt = 0;
		for (int i = 0; i < n; i++) {
			if (!use[i]) {
				m += choose[n - i - 1][k - cnt - 1];
			}
			cnt += use[i];
		}

		cout << m << endl;

		return 0;
	}
}

#if defined(choose2num) && !defined(checker)
int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	while (!cin.eof()) {
		choose2num::main();
	}
	choose2num::wait();
#else   
	freopen("choose2num.in ", "r", stdin);
	freopen("choose2num.out", "w", stdout);
	choose2num::main();
#endif
	return 0;
}
#endif