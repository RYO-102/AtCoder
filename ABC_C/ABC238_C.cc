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

const ll INF_LL = 1LL << 60;
const int INF_INT = 1073741823;
const ll MOD = 998244353;
//const ll MOD = 1000000007;
const double PI = acos(-1);

const vll dy{-1, 0, 1, 0}, dx{0, 1, 0, -1};
//const vll dy{-1, -1, 0, 1, 1, 1, 0, -1}, dx{0, 1, 1, 1, 0, -1, -1, -1};

//Declaration
ll N;

ll modinv(ll a, ll m) {
	ll b = m, u = 1, v = 0;
	while(b){
		ll t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

	//ABC238_C
	cin >> N;

	ll digit = 0, tmp = N;
	while(tmp > 0){
		tmp /= 10;
		digit++;
	}

	ll ans = 0, power = 1;
	ll inverse_element = modinv(2, MOD);

	rep(i, 0, digit - 1){
		ll num = (power % MOD * 9) % MOD;

		ans += (1 + num) % MOD * num % MOD * inverse_element % MOD;
		power *= 10;

		ans %= MOD;
	}

	ll num = (N % MOD - (power - 1) % MOD) % MOD;
	if(num < 0) num += MOD;

	ans += (1 + num) % MOD * num % MOD * inverse_element % MOD;
	ans %= MOD;

	cout << ans << endl;

	return 0;
}