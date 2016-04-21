#ifdef LOCAL
#include "task_selection.h"
#include "checker.h"
#else
#define num2choose task
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

namespace num2choose {

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
	ll choose[MAXN][MAXN];
	vector<ll> ans;

	void solve(ll pos, ll n, ll k, ll left) {
		if (k == 0) {
			for (auto& i : ans) {
				cout << i << ' ';
			}
			cout << endl;
			return;
		}
		if (left < choose[n - 1][k - 1]) {
			ans.push_back(pos + 1);
			solve(pos + 1, n - 1, k - 1, left);
		}
		else {
			solve(pos + 1, n - 1, k, left - choose[n - 1][k - 1]);
		}
	}

	int main() {
		cin >> n >> k >> m;
		choose[0][0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				choose[i][j] = choose[i - 1][j] + (j > 0 ? choose[i - 1][j - 1] : 0);
			}
		}
		solve(0, n, k, m);

		return 0;
	}
}

#if defined(num2choose) && !defined(checker)
int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	while (!cin.eof()) {
		num2choose::main();
	}
	num2choose::wait();
#else   
	freopen("num2choose.in ", "r", stdin);
	freopen("num2choose.out", "w", stdout);
	num2choose::main();
#endif
	return 0;
}
#endif