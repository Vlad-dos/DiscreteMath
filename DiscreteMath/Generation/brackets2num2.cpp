#ifdef LOCAL
#include "task_selection.h"
#include "checker.h"
#else
#define brackets2num2 task
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

namespace brackets2num2 {

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
	string s;

	int main() {
		cin >> s;
		n = s.size() / 2;
		for (int i = 0; i < 2 * n; i++) {
			for (int j = 0; j < 2 * n; j++) {
				if (i == 0) {
					if (j == 0) {
						brackets[i][j] = 1;
					}
					else {
						brackets[i][j] = 0;
					}
				}
				else {
					brackets[i][j] = (j > 0 ? brackets[i - 1][j - 1] : 0) + brackets[i - 1][j + 1];
				}
			}
		}

		ll k = 0;
		ll balance = 0;
		stack<char> st;
		for (int i = 0; i < 2 * n; i++) {
			if (s[i] == '(') {
				st.push(')');
				balance++;
				continue;
			}
			else {
				k += brackets[2 * n - i - 1][balance + 1] * (1 << ((2 * n - i - 2 - balance) / 2));
			}
			if (!st.empty() && st.top() == ')') {
				if (s[i] == ')') {
					st.pop();
					balance--;
					continue;
				}
				else {
					k += brackets[2 * n - i - 1][balance - 1] * (1 << ((2 * n - i - balance) / 2));
				}
			}
			if (s[i] == '[') {
				st.push(']');
				balance++;
				continue;
			}
			else {
				k += brackets[2 * n - i - 1][balance + 1] * (1 << ((2 * n - i - 2 - balance) / 2));
			}
			if (s[i] == ']') {
				st.pop();
				balance--;
				continue;
			}
		}

		cout << k << endl;

		return 0;
	}
}

#if defined(brackets2num2) && !defined(checker)
int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	while (!cin.eof()) {
		brackets2num2::main();
	}
	brackets2num2::wait();
#else   
	freopen("brackets2num2.in ", "r", stdin);
	freopen("brackets2num2.out", "w", stdout);
	brackets2num2::main();
#endif
	return 0;
}
#endif