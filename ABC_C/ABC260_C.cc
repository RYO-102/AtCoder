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
ll N, X, Y;

map<ll, ll> memo_red, memo_blue;

ll dfs(bool red, ll level){
	ll num;

	if(level == 1){
		if(red) num = 0;
		else num = 1;
	}else if(red){
		if(memo_red[level]){
			num = memo_red[level];
		}else{
			num = dfs(true, level - 1) + dfs(false, level) * X;
			memo_red[level] = num;
		}
	}else{
		if(memo_blue[level]){
			num =  memo_blue[level];
		}else{
			num = dfs(true, level - 1) + dfs(false, level - 1) * Y;
		}
	}

	return num;
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

	//ABC260_C
	cin >> N >> X >> Y;

	ll ans = dfs(true, N);

	cout << ans << endl;

	return 0;
}