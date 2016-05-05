#ifdef LOCAL
#include "task_selection.h"
#include "checker.h"
#else
#define markchain task
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

namespace markchain {

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

	template<typename T> class matrix {
		vector< vector<T> > data;
	public:
		int n, m;

		matrix(): n(0), m(0) {}

		matrix(initializer_list< initializer_list<T> > a) {
			n = a.size();
			data = vector< vector<T> >();
			m = a.begin()->size();
			for (auto i : a) {
				assert(static_cast<int>(i.size()) == m);
				data.push_back(vector<T>());
				auto tmp = &data.back();
				for (auto j : i) {
					tmp->push_back(j);
				}
			}
		}

		matrix(int N, int M) {
			n = N;
			m = M;
			data = vector< vector<T> >(n);
			for (int i = 0; i < n; i++) {
				data[i] = vector<T>(m);
			}
		}

		T& operator()(const int i, const int j) {
			return data[i][j];
		}

		matrix operator*(matrix b) {
			assert(m == b.n);
			matrix result(n, b.m);

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < b.m; j++) {
					T sum = 0;
					for (int k = 0; k < m; k++) {
						sum += operator()(i, k) * b(k, j);
					}
					result(i, j) = sum;
				}
			}

			return result;
		}

		matrix one() const
		{
			assert(n == m);
			matrix result(n, m);
			for (int i = 0; i < n; i++) {
				result(i, i) = 1;
			}
			return result;
		}

		void print(std::ostream& stream) {
			for (auto i : data) {
				for (auto j : i) {
					stream << j << ' ';
				}
				stream << '\n';
			}
		}
		
		static matrix fast_pow(matrix a, ll k) {
			ll l = k;
			matrix b = a;
			matrix x = a.one();
			while (l > 0) {
				if (l % 2 == 0) {
					b = b * b;
					l /= 2;
				} else {
					x = b * x;
					l -= 1;
				}
			}
			return x;
		}

		friend ostream& operator<< (ostream& stream, matrix& tmp);
	};

	//template<typename T>
	ostream& operator<< (ostream& stream, matrix<double>& tmp) {
		tmp.print(stream);
		return stream;
	}

	int n;

	int main() {
		cin >> n;
		matrix<double> P(n, n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> P(i, j);
			}
		}

		P = matrix<double>::fast_pow(P, 1000);
		cout.precision(6);
		for (int i = 0; i < n; i++) {
			cout << P(0, i) << endl;
		}

		cerr << P;

		return 0;
	}
}

#if defined(markchain) && !defined(checker)
int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	while (!cin.eof()) {
		markchain::main();
	}
	markchain::wait();
#else   
	freopen("markchain.in ", "r", stdin);
	freopen("markchain.out", "w", stdout);
	markchain::main();
#endif
	return 0;
}
#endif