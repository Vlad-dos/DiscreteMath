#ifdef LOCAL
#include "task_selection.h"
#include "checker.h"
#else
#define num2brackets task
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

namespace num2brackets {

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
	ll brackets[MAXN][MAXN];

	int main() {
		cin >> n >> k;
		for (int i = 0; i < 2 * n; i++) {
			for (int j = 0; j < 2 * n; j++) {
				if (i == 0) {
					if (j == 0) {
						brackets[i][j] = 1;
					}
					else {
						brackets[i][j] = 0;
					}
				} else {
					brackets[i][j] = (j > 0 ? brackets[i - 1][j - 1] : 0) + brackets[i - 1][j + 1];
				}
			}
		}

		int balance = 0;
		string ans = "";
		for (int i = 0; i < 2 * n; i++) {
			if (brackets[2 * n - (i + 1)][balance + 1] > k) {
				ans += "(";
				balance++;
			} else {
				k -= brackets[2 * n - (i + 1)][balance + 1];
				ans += ")";
				balance--;
			}
		}

		cout << ans << endl;
		
		return 0;
	}
}

#if defined(num2brackets) && !defined(checker)
int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	while (!cin.eof()) {
		num2brackets::main();
	}
	num2brackets::wait();
#else   
	freopen("num2brackets.in ", "r", stdin);
	freopen("num2brackets.out", "w", stdout);
	num2brackets::main();
#endif
	return 0;
}
#endif