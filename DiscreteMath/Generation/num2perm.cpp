#ifdef LOCAL
#include "task_selection.h"
#include "checker.h"
#else
#define num2perm task
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

namespace num2perm {

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
		cin >> n >> k;
		fact[0] = 1;
		for (ll i = 0; i < n; i++) {
			pos[i] = i + 1;
		}
		for (ll i = 1; i <= n; i++) {
			fact[i] = fact[i - 1] * i;
		}

		vector<ll> ans;
		for (ll i = 0; i < n; i++) {
			ll cur = 0;
			ll j = 0;
			while (cur + fact[n - i - 1] <= k) {
				cur += fact[n - i - 1];
				j++;
			}
			ll cnt = 0;
			for (ll i = 0; i < n; i++) {
				if (pos[i]) {
					cnt++;
					if (cnt > j) {
						ans.push_back(pos[i]);
						pos[i] = 0;
						break;
					}
				}
			}
 			k -= cur;
		}
		write(ans, " ");
		cout << endl;

		return 0;
	}
}

#if defined(num2perm) && !defined(checker)
int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	while (!cin.eof()) {
		num2perm::main();
	}
	num2perm::wait();
#else   
	freopen("num2perm.in ", "r", stdin);
	freopen("num2perm.out", "w", stdout);
	num2perm::main();
#endif
	return 0;
}
#endif