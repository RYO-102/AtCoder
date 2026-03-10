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
ll N, K;
vector<string> S;


int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

	//ABC249_C
	cin >> N >> K;
	S.resize(N);
	rep(i, 0, N) cin >> S.at(i);

	ll ans = 0;

	// 2^N通りの部分集合を全探索
	rep(bit, 0, (1 << N)){
		map<char, ll> bucket;
		ll include = 0;

		// 各ビットに対応する要素を選ぶかどうか
		rep(i, 0, N){
			if(bit & (1 << i)){
				rep(j, 0, S.at(i).length()) bucket[S.at(i).at(j)]++;
			}
		}

		for(pair<char, ll> p : bucket){
			if(p.second == K) include++;
		}

		chmax(ans, include);
	}

	cout << ans << endl;

	return 0;
}