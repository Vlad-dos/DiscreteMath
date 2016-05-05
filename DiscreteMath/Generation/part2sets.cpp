#ifdef LOCAL
#include "task_selection.h"
#else
#define part2sets task
#endif

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <cassert>

#include <numeric>

using namespace std;

namespace part2sets {

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

	int n, m, k;
	vector< vector<int> > partition;

	vector< vector<int> > next_partition(vector< vector<int> > part) {
		set<int> used;
		bool f = false;
		for (int i = part.size() - 1; i >= 0; i--) {
			if (!used.empty() && *used.rbegin() > part[i].back()) {
				int x = part[i].back();
				auto a = upper_bound(all(used), x);
				part[i].push_back(*a);
				used.erase(a);
				break;
			}
			for (int j = part[i].size() - 1; j >= 0; j--) {
				if (!used.empty() && j && *used.rbegin() > part[i][j]) {
					int x = part[i][j];
					auto a = upper_bound(all(used), x);
					part[i][j] = *a;
					used.erase(a);
					used.insert(x);
					f = true;
					break;
				}
				used.insert(part[i][j]);
				part[i].erase(part[i].begin() + j);
				if (part[i].empty()) {
					part.erase(part.begin() + i);
				}
			}
			if (f) break;
		}
		for (int i : used) {
			part.push_back(vector<int>());
			part.back().push_back(i);
		}
		return part;
	}

	int main() {
		cin >> n >> k;

		partition.push_back(vector<int>(n));
		for (auto i = 0; i < n; i++) {
			partition[0][i] = i + 1;
		}
		if (k == 1) {
			write(partition[0], ' ');
			return 0;
		}
		partition = next_partition(partition);

		while (partition.size() != 1) {
			if (partition.size() == k) {
				for (auto i : partition) {
					write(i, ' ');
					cout << '\n';
				}
				cout << '\n';
			}
			partition = next_partition(partition);
		}

		return 0;
	}
}

#if defined(part2sets) && !defined(checker)
int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	while (!cin.eof()) {
		part2sets::main();
	}
	part2sets::wait();
#else   
	freopen("part2sets.in ", "r", stdin);
	freopen("part2sets.out", "w", stdout);
	part2sets::main();
#endif
	return 0;
}
#endif