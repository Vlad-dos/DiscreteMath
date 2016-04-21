#ifdef LOCAL
#include "task_selection.h"
#include "checker.h"
#else
#define perm2num task
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

namespace perm2num {

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

	ll n, k;
	ll fact[MAXN];
	ll pos[MAXN];

	int main() {
		cin >> n;
		vector<ll> perm(n);
		for (int i = 0; i < n; i++) {
			cin >> perm[i];
			pos[i] = 1;
		}
		fact[0] = 1;
		for (ll i = 1; i <= n; i++) {
			fact[i] = fact[i - 1] * i;
		}

		ll k = 0;
		for (ll i = 0; i < n; i++) {
			ll cnt = 0;
			pos[perm[i]] = 0;
			for (ll j = 1; j < perm[i]; j++) {
				cnt += pos[j];
			}
			k += cnt * fact[n - i - 1];
		}
		cout << k;
		cout << endl;

		return 0;
	}
}

#if defined(perm2num) && !defined(checker)
int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	while (!cin.eof()) {
		perm2num::main();
	}
	perm2num::wait();
#else   
	freopen("perm2num.in ", "r", stdin);
	freopen("perm2num.out", "w", stdout);
	perm2num::main();
#endif
	return 0;
}
#endif