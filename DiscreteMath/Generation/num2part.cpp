#ifdef LOCAL
#include "task_selection.h"
#include "checker.h"
#else
#define num2part task
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

namespace num2part {

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
		cin >> n >> k;

		for (int i = 0; i <= n; i++) {
			for (int j = n; j >= 0; j--) {
				if (i == 0) {
					parts[i][j] = 1;
				} else if (j == i) {
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

		int pos = 1;
		vector<int> ans;
		while (n > 0) {
			if (parts[n - pos][pos] > k) {
				ans.push_back(pos);
				n -= pos;
			}
			else {
				k -= parts[n - pos][pos];
				pos++;
			}
		}

		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << (i == ans.size() - 1 ? "" : "+");
		}

		return 0;
	}
}

#if defined(num2part) && !defined(checker)
int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	while (!cin.eof()) {
		num2part::main();
	}
	num2part::wait();
#else   
	freopen("num2part.in ", "r", stdin);
	freopen("num2part.out", "w", stdout);
	num2part::main();
#endif
	return 0;
}
#endif