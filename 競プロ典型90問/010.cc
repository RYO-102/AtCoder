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
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


#define rep(i, begin, limit) for(ll i = (ll)begin; i < (ll)limit; i++)
#define rrep(i, begin, limit) for(ll i = (ll)begin; i > (ll)limit; i--)
#define all(vec_name) vec_name.begin(), vec_name.end()
#define rall(vec_name) vec_name.rbegin(), vec_name.rend()
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define EuclideanDistance(X1, Y1, X2, Y2) sqrt((X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2))

const ll LL_INF = 1LL << 60;
const int INT_INF = 1073741823;
const ll MOD = 998244353;
//const ll MOD = 1000000007;
const double PI = acos(-1);

const vll dy{-1, 0, 1, 0}, dx{0, 1, 0, -1};
//const vll dy{-1, -1, 0, 1, 1, 1, 0, -1}, dx{0, 1, 1, 1, 0, -1, -1, -1};

//Declaration
ll N, Q;
vll C, P, L, R;


int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

	//‹£ƒvƒ“TŒ^90–â 010
	cin >> N;
	C.resize(N), P.resize(N);
	rep(i, 0, N) cin >> C.at(i) >> P.at(i);
	cin >> Q;
	L.resize(Q), R.resize(Q);
	rep(i, 0, Q) cin >> L.at(i) >> R.at(i);

	vll presum_1(N + 1, 0), presum_2(N + 1, 0);

	rep(i, 0, N){
		presum_1.at(i + 1) = presum_1.at(i);
		presum_2.at(i + 1) = presum_2.at(i);

		if(C.at(i) == 1) presum_1.at(i + 1) += P.at(i);
		else if(C.at(i) == 2) presum_2.at(i + 1) += P.at(i);
	}

	rep(i, 0, Q){
		cout << presum_1.at(R.at(i)) - presum_1.at(L.at(i) - 1) << ' ';
		cout << presum_2.at(R.at(i)) - presum_2.at(L.at(i) - 1) << endl;
	}

	return 0;
}