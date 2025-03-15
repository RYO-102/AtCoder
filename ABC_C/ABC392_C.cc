//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <bitset>
#include <set>
#include <regex>
#include <cstdint>
#include <queue>
#include <stack>
#include <ctime>
#include <functional>
#include <cassert>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using graph = vector<vector<int>>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i, begin, limit) for(ll i = (ll)begin; i < (ll)limit; i++)
#define rrep(i, begin, limit) for(ll i = (ll)begin; i > (ll)limit; i--)
#define all(vec_name) vec_name.begin(), vec_name.end()
#define rall(vec_name) vec_name.rbegin(), vec_name.rend()
#define vvec(type) vector<vector<type>>

const long long ll_INF = 1LL << 60;

//Declaration
int N;
vector<int> P, Q;

int main(){
	//ABC392_C
	cin >> N;
	P.resize(N), Q.resize(N);
	rep(i, 0, N) cin >> P.at(i);
	rep(i, 0, N) cin >> Q.at(i);

	map<int, int> bib;
	rep(i, 0, N){
		bib.insert({Q.at(i), i + 1});
	}

	map<int, int> from_to;
	rep(i, 0, N){
		from_to.insert({i + 1, P.at(i)});
	}

	rep(i, 0, N){
		int from = bib.at(i + 1);
		int to = from_to.at(from);

		cout << Q.at(to - 1) << ' ';
	}

	cout << endl;

	return 0;
}