#ifdef LOCAL
#else
#define brackets task
#endif

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <vector>
#include <cassert>

using namespace std;

namespace brackets {

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
#define write(a, c) for (auto j : a) cout << j << c;
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

	vector< vector <char> > ans;
	vector<char> cur;
	bool use[MAXN];
	int n, k;

	void gena(int score) {
		if (score > n) {
			return;
		}
		if (cur.size() == n * 2) {
			if (score == 0) 
				ans.push_back(cur);
			return;
		}
		cur.push_back('(');
		gena(score + 1);
		cur.pop_back();
		if (score > 0) {
			cur.push_back(')');
			gena(score - 1);
			cur.pop_back();
		}
	}

	int main() {
		cin >> n >> k;
		gena(0);

		for (auto& i : ans) {
			write(i, "");
			cout << endl;
		}

		return 0;
	}
}

#if defined(brackets) && !defined(checker)
int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	while (!cin.eof()) {
		brackets::main();
	}
	brackets::wait();
#else   
	freopen("brackets.in ", "r", stdin);
	freopen("brackets.out", "w", stdout);
	brackets::main();
#endif
	return 0;
}
#endif