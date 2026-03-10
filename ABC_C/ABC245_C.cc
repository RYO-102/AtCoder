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
vll A, B;

int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

	//ABC245_C
	cin >> N >> K;
	A.resize(N), B.resize(N);
	rep(i, 0, N) cin >> A.at(i);
	rep(i, 0, N) cin >> B.at(i);

	vector<vector<bool>> dp(N, vector<bool>(2, false));
	rep(i, 0, 2) dp.at(0).at(i) = true;

	rep(i, 0, N - 1){
		if(dp.at(i).at(0)){
			if(abs(A.at(i) - A.at(i + 1)) <= K) dp.at(i + 1).at(0) = true;
			if(abs(A.at(i) - B.at(i + 1)) <= K) dp.at(i + 1).at(1) = true;
		}

		if(dp.at(i).at(1)){
			if(abs(B.at(i) - A.at(i + 1)) <= K) dp.at(i + 1).at(0) = true;
			if(abs(B.at(i) - B.at(i + 1)) <= K) dp.at(i + 1).at(1) = true;
		}
	}

	if(dp.at(N - 1).at(0) || dp.at(N - 1).at(1)) Yes;
	else No;

	return 0;
}