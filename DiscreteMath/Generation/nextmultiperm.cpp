#ifdef LOCAL
#include "task_selection.h"
#include "checker.h"
#else
#define nextmultiperm task
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

namespace nextmultiperm {

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

	int b[MAXN];
	int n;

	void gena() {
		int i = n - 2;
		while ((i > 0) && (b[i] >= b[i + 1]))
			i--;
		if (i >= 0) {
			int pos = i + 1;
			for (int j = i + 1; j < n; j++) {
				if (b[j] < b[pos] && b[pos] > b[i])
					pos = j;
			}
			swap(b[i], b[pos]);
			reverse(b + i + 1, b + n - 1);
		}
		else {
			for (int i = 0; i < n; i++) {
				b[i] = 0;
			}
		}
	}

	int main() {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		gena();
		for (int i = 0; i < n; i++) {
			cout << b[i] << ' ';
		}
		cout << endl;

		return 0;
	}
}

#if defined(nextmultiperm) && !defined(checker)
int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	while (!cin.eof()) {
		nextmultiperm::main();
	}
	nextmultiperm::wait();
#else   
	freopen("nextmultiperm.in ", "r", stdin);
	freopen("nextmultiperm.out", "w", stdout);
	nextmultiperm::main();
#endif
	return 0;
}
#endif