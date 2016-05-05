#ifdef LOCAL
#include "task_selection.h"
#include "checker.h"
#else
#define nextsetpartition task
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

namespace nextsetpartition {

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

	int n, m;
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
		cin >> n >> m;
 		while (n) {
			partition = vector< vector<int> >(m);
			for (int i = 0; i < m; i++) {
				string s = "";
				while(s == "")
					getline(cin, s);
				istringstream line(s);
				int x;
				partition[i] = vector<int>();
				while (line >> x) {
					partition[i].push_back(x);
				}
			}

			vector< vector<int> > next_part = next_partition(partition);

			cout << n << ' ' << next_part.size() << endl;
			for (auto i : next_part) {
				for (auto j : i) {
					cout << j << ' ';
				}
				cout << '\n';
			}
			cout << endl;

			cin >> n >> m;
		}

		return 0;
	}
}

#if defined(nextsetpartition) && !defined(checker)
int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	while (!cin.eof()) {
		nextsetpartition::main();
	}
	nextsetpartition::wait();
#else   
	freopen("nextsetpartition.in ", "r", stdin);
	freopen("nextsetpartition.out", "w", stdout);
	nextsetpartition::main();
#endif
	return 0;
}
#endif