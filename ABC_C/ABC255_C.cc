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

const ll LL_INF = 1LL << 62;
const int INT_INF = 1073741823;
const ll MOD = 998244353;
//const ll MOD = 1000000007;
const double PI = acos(-1);

const vll dy{-1, 0, 1, 0}, dx{0, 1, 0, -1};
//const vll dy{-1, -1, 0, 1, 1, 1, 0, -1}, dx{0, 1, 1, 1, 0, -1, -1, -1};

//Declaration
ll X, A, D, N;

int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

	//ABC255_C
	cin >> X >> A >> D >> N;

	if(D < 0){
		A = A + (N - 1) * D;
		D *= -1;
	}

	// [ng, ok)‚à‚µ‚­‚Í(ok, ng]
	ll ok = N, ng = 0;

	// ”¼ŠJ‹æŠÔ‚Ì“ñ•ª’Tõ
	while(abs(ok - ng) > 1){
		ll mid = (ok + ng) / 2;
		ll an = A + (mid - 1) * D;

		if(X <= an){
			ok = mid;
		}else{
			ng = mid;
		}
	}

	ll ans = LL_INF;
	if(ok > 1) chmin(ans, abs(X - (A + (ok - 2) * D)));
	chmin(ans, abs(X - (A + (ok - 1) * D)));

	cout << ans << endl;

	return 0;
}