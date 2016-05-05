#ifdef LOCAL
#include "task_selection.h"
#include "checker.h"
#else
#define absmarkchain task
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

namespace absmarkchain {

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
	const ll MAXN = 500;
	const int INF = 2e9 + 1;
	const ll LONG_INF = 8e18;
	const ll MOD = 1e9 + 7;
	const ld e = 1e-6;
	const ll C = 500;
	const ll dx[4] = {-1, 0, 1, 0};
	const ll dy[4] = {0, 1, 0, -1};

	int n, m;
	double P[MAXN][MAXN];
	vector< vector<double> > Q, R, N, G;
	bool is_absorb[MAXN];

	int main() {
		cin >> n >> m;
		for (auto i = 0; i < m; i++) {
			int a, b;
			double w;
			cin >> a >> b >> w;
			a--, b--;
			P[a][b] = w;
			if (a == b && w > 1 - e) {
				is_absorb[a] = true;
			}
		}

		for (auto i = 0; i < n; i++) {
			if (!is_absorb[i]) {
				Q.push_back(vector<double>());
				R.push_back(vector<double>());
				for (auto j = 0; j < n; j++) {
					if (is_absorb[j]) {
						R.back().push_back(P[i][j]);
					} else {
						Q.back().push_back(P[i][j]);
					}
				}
			}
		}

		for (auto i = 0; i < Q.size(); i++) {
			N.push_back(vector<double>());
			for (auto j = 0; j < Q.size(); j++) {
				N.back().push_back(i == j);
				Q[i][j] = (i == j) - Q[i][j];
			}
		}

		for (auto i = 0; i < Q.size(); i++) {
			if (Q[i][i] != 1) {
				auto tmp = Q[i][i];
				auto tmp_func = [tmp, i](double& a) {
					a /= tmp;
				};
				for_each(all(Q[i]), tmp_func);
				for_each(all(N[i]), tmp_func);
			}
			for (auto j = 0; j < Q.size(); j++) {
				if (i != j) {
					auto tmp = Q[j][i];
					for (auto k = 0; k < Q.size(); k++) {
						Q[j][k] -= tmp * Q[i][k];
						N[j][k] -= tmp * N[i][k];
					}
				}
			}
		}

		for (auto i = 0; i < Q.size(); i++) {
			G.push_back(vector<double>());
			for (auto j = 0; j < R[0].size(); j++) {
				double sum = 0;
				for (auto k = 0; k < Q.size(); k++) {
					sum += N[i][k] * R[k][j];
				}
				G[i].push_back(sum);
			}
		}

		if (is_absorb[0]) {
			cout << "1\n";
			for (auto i = 0; i < n - 1; i++) {
				cout << "0\n";
			}
			return 0;
		}
		int cnt = 0;
		double sum = 0;
		cout.precision(15);
		for (auto i = 0; i < n; i++) {
			if (is_absorb[i]) {
				sum += G[0][cnt];
				cout << G[0][cnt++] << endl;
			} else {
				cout << 0 << endl;
			}
		}

		cerr << "sum = " << sum << endl;

		return 0;
	}
}

#if defined(absmarkchain) && !defined(checker)
int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	while (!cin.eof()) {
		absmarkchain::main();
	}
	absmarkchain::wait();
#else   
	freopen("absmarkchain.in ", "r", stdin);
	freopen("absmarkchain.out", "w", stdout);
	absmarkchain::main();
#endif
	return 0;
}
#endif