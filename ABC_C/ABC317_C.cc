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

#define DEBUG
#ifdef DEBUG
#define debug(x) cerr << #x << " = " << (x) << endl
#else
#define debug(x)
#endif

const ll LL_INF = 1LL << 60;
const int INT_INF = 1073741823;
const double PI = acos(-1);
const ll MOD = 998244353;
//const ll MOD = 1000000007;
const vll dy{-1, 0, 1, 0}, dx{0, 1, 0, -1};
//const vll dy{-1, -1, 0, 1, 1, 1, 0, -1}, dx{0, 1, 1, 1, 0, -1, -1, -1};

void solve(){
	ll N, M;
	cin >> N >> M;
	vll A(M), B(M), C(M);
	rep(i, 0, M) cin >> A[i] >> B[i] >> C[i];

	vvll length(N, vll(N, 0));
	rep(i, 0, M){
		length[A[i] - 1][B[i] - 1] = C[i];
		length[B[i] - 1][A[i] - 1] = C[i];
	}

	ll ans = 0;
	vll route(N);
	rep(i, 0, N) route[i] = i + 1;

	do{
		ll sum = 0;

		rep(i, 0, N - 1){
			if(length[route[i] - 1][route[i + 1] - 1] == 0) break;

			sum += length[route[i] - 1][route[i + 1] - 1];
		}

		chmax(ans, sum);
	}while(next_permutation(all(route)));

	cout << ans << endl;
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

	//ABC317_C
	int query = 1;
	//cin >> query;
	while(query--) solve();

	return 0;
}