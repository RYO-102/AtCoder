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
vector<string> S;

int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

	//ABC241_C
	cin >> N;
	S.resize(N);
	rep(i, 0, N) cin >> S.at(i);

	bool ans = false;

	rep(i, 0, N){
		rep(j, 0, N){
			ll black = 0;

			//c
			if(N - i >= 6){
				rep(k, 0, 6){
					if(S.at(i + k).at(j) == '#') black++;
				}

				if(black >= 4) ans = true;
			}

			//‰¡
			black = 0;
			
			if(N - j >= 6){
				rep(k, 0, 6){
					if(S.at(i).at(j + k) == '#') black++;
				}

				if(black >= 4) ans = true;
			}

			//‰EŽÎ‚ß‰º
			black = 0;

			if(N - i >= 6 && N - j >= 6){
				rep(k, 0, 6){
					if(S.at(i + k).at(j + k) == '#') black++;
				}

				if(black >= 4) ans = true;
			}

			//¶ŽÎ‚ß‰º
			black = 0;

			if(N - i >= 6 && j + 1 >= 6){
				rep(k, 0, 6){
					if(S.at(i + k).at(j - k) == '#') black++;
				}

				if(black >= 4) ans = true;
			}
		}
	}

	if(ans) Yes;
	else No;

	return 0;
}