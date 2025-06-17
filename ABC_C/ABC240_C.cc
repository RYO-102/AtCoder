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
ll N, X;
vll a, b;

int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

	//ABC240_C
	cin >> N >> X;
	a.resize(N), b.resize(N);
	rep(i, 0, N) cin >> a.at(i) >> b.at(i);

	vector<vector<bool>> dp(N + 1, vector<bool>(X + 1, false));

	dp.at(0).at(0) = true;

	rep(i, 0, N){
		rep(j, 0, X + 1){
			if(j - a.at(i) >= 0) dp.at(i + 1).at(j) = dp.at(i + 1).at(j) | dp.at(i).at(j - a.at(i));
			if(j - b.at(i) >= 0) dp.at(i + 1).at(j) = dp.at(i + 1).at(j) | dp.at(i).at(j - b.at(i));
		}
	}

	if(dp.at(N).at(X)) Yes;
	else No;

	return 0;
}