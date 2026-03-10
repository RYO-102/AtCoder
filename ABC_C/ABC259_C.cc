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
string S, T;

int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

	//ABC259_C
	cin >> S >> T;

	vector<pair<char, ll>> s_comp, t_comp;
	ll ren = 0;
	rep(i, 0, S.length()){
		ren++;

		if(i == S.length() - 1 || S.at(i) != S.at(i + 1)){
			s_comp.push_back(make_pair(S.at(i), ren));
			ren = 0;
		}
	}

	rep(i, 0, T.length()){
		ren++;

		if(i == T.length() - 1 || T.at(i) != T.at(i + 1)){
			t_comp.push_back(make_pair(T.at(i), ren));
			ren = 0;
		}
	}

	bool ans = (s_comp.size() == t_comp.size() ? true : false);

	rep(i, 0, min(s_comp.size(), t_comp.size())){
		if(s_comp.at(i).first != t_comp.at(i).first) ans = false;

		if(s_comp.at(i) > t_comp.at(i) || (s_comp.at(i).second < 2 && s_comp.at(i) < t_comp.at(i))) ans = false;
	}

	if(ans) Yes;
	else No;

	return 0;
}