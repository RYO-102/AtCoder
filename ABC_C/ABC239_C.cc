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

const vll dy{-1, 0, 1, 0}, dx{0, 1, 0, -1};
//const vll dy{-1, -1, 0, 1, 1, 1, 0, -1}, dx{0, 1, 1, 1, 0, -1, -1, -1};

//Declaration
ll x1, yy1, x2, y2;

int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

	//ABC239_C
	cin >> x1 >> yy1 >> x2 >> y2;

	set<pll> locate;

	rep(i, -2, 3){
		rep(j, -2, 3){
			if(abs(i) == abs(j) || i == 0 || j == 0) continue;

			locate.insert(make_pair(x1 + i, yy1 + j));
		}
	}

	bool ans = false;
	
	rep(i, -2, 3){
		rep(j, -2, 3){
			if(abs(i) == abs(j) || i == 0 || j == 0) continue;

			if(locate.count(make_pair(x2 + i, y2 + j))) ans = true;
		}
	}

	if(ans) Yes;
	else No;

	return 0;
}