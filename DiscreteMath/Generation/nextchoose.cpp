#ifdef LOCAL
#include "task_selection.h"
#include "checker.h"
#else
#define nextchoose task
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

namespace nextchoose {

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

	int n, k;
	vector<int> choose;
	vector<int> tmp;
	void gena() {
		choose.push_back(n + 1);
		int i;
		for (i = k - 1; i >= 0 && (choose[i + 1] - choose[i]) < 2; i--);
		if (i >= 0) {
			choose[i]++;
			for (int j = i + 1; j < k; j++) {
				choose[j] = choose[j - 1] + 1;
			}
		}
		else {
			choose = vector<int>(0);
			choose.push_back(-1);
			choose.push_back(322);
		}
	}

	int main() {
		cin >> n >> k;
		choose = vector<int>(k);
		for (int i = 0; i < k; i++) {
			cin >> choose[i];
		}
		gena();
		choose.pop_back();
		write(choose, ' ');
		cout << endl;

		return 0;
	}
}

#if defined(nextchoose) && !defined(checker)
int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	while (!cin.eof()) {
		nextchoose::main();
	}
	nextchoose::wait();
#else   
	freopen("nextchoose.in ", "r", stdin);
	freopen("nextchoose.out", "w", stdout);
	nextchoose::main();
#endif
	return 0;
}
#endif