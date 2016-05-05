#ifdef LOCAL
#include "task_selection.h"
#include "checker.h"
#else
#define nextpartition task
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

namespace nextpartition {

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

	int n;
	vector<int> part;

	void gena() {
		part[part.size() - 1]--;
		part[part.size() - 2]++;
		if (part[part.size() - 2] > part[part.size() - 1]) {
			part[part.size() - 2] += part[part.size() - 1];
			part.pop_back();
		}
		else {
			while (part[part.size() - 2] * 2 <= part[part.size() - 1]) {
				part.push_back(part[part.size() - 1] - part[part.size() - 2]);
				part[part.size() - 2] = part[part.size() - 3];
			}
		}
	}

	int main() {
		string number;
		string s;
		cin >> s;

		for (char a : s) {
			if (a == '=') {
				n = atoi(number.c_str());
				number.clear();
			}
			else if (a == '+') {
				part.push_back(atoi(number.c_str()));
				number.clear();
			}
			else {
				number += a;
			}
		}
		part.push_back(atoi(number.c_str()));

		if (part.size() == 1) {
			cout << "No solution\n";
			return 0;
		}

		gena();

		cout << n << "=";
		for (int i = 0; i < (int)part.size(); i++) {
			cout << part[i];
			if (i != part.size() - 1) {
				cout << '+';
			}
		}
		cout << endl;

		return 0;
	}
}

#if defined(nextpartition) && !defined(checker)
int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	while (!cin.eof()) {
		nextpartition::main();
	}
	nextpartition::wait();
#else   
	freopen("nextpartition.in ", "r", stdin);
	freopen("nextpartition.out", "w", stdout);
	nextpartition::main();
#endif
	return 0;
}
#endif