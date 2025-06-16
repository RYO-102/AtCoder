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
vector<vector<char>> S, T;

int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

	//ABC218_C
	cin >> N;
	S.resize(N, vector<char>(N)), T.resize(N, vector<char>(N));
	rep(i, 0, N){
		rep(j, 0, N) cin >> S.at(i).at(j);
	}
	rep(i, 0, N){
		rep(j, 0, N) cin >> T.at(i).at(j);
	}

	ll S_left = N, S_top = N, S_right = -1, S_bottom = -1;
	ll T_left = N, T_top = N, T_right = -1, T_bottom = -1;

	rep(i, 0, N){
		rep(j, 0, N){
			if(S.at(i).at(j) == '#'){
				S_left = min(S_left, j);
				S_top = min(S_top, i);
				S_right = max(S_right, j);
				S_bottom = max(S_bottom, i);
			}

			if(T.at(i).at(j) == '#'){
				T_left = min(T_left, j);
				T_top = min(T_top, i);
				T_right = max(T_right, j);
				T_bottom = max(T_bottom, i);
			}
		}
	}

	S_right++, S_bottom++, T_right++, T_bottom++;
	
	bool ans = false;

	//cout << S_left << ' ' << S_top << ' ' << S_right << ' ' << S_bottom << endl;
	//cout << T_left << ' ' << T_top << ' ' << T_right << ' ' << T_bottom << endl;

	//0‹‚Æ180‹‰ñ“]‚Ì‚Æ‚«‚É•‚Æ‚‚³‚ª“¯‚¶‚Å‚ ‚ê‚Î
	if(S_right - S_left == T_right - T_left && S_bottom - S_top == T_bottom - T_top){
		bool flag = true;

		//0‹
		rep(i, 0, S_bottom - S_top){
			rep(j, 0, S_right - S_left){
				if(S.at(i + S_top).at(j + S_left) != T.at(i + T_top).at(j + T_left)) flag = false;
			}
		}

		if(flag) ans = true;

		flag = true;

		//180‹
		rep(i, 0, S_bottom - S_top){
			rep(j, 0, S_right - S_left){
				if(S.at(S_bottom - i - 1).at(S_right - j - 1) != T.at(i + T_top).at(j + T_left)) flag = false;
			}
		}

		if(flag) ans = true;
	}

	//90‹‚Æ270‹‰ñ“]‚Ì‚Æ‚«‚É•‚Æ‚‚³‚ª“¯‚¶‚Å‚ ‚ê‚Î
	if(S_bottom - S_top == T_right - T_left && S_right - S_left == T_bottom - T_top){
		bool flag = true;
		
		//90‹
		rep(i, 0, S_right - S_left){
			rep(j, 0, S_bottom - S_top){
				if(S.at(j + S_top).at(S_right - i - 1) != T.at(i + T_top).at(j + T_left)) flag = false;
			}
		}

		if(flag) ans = true;

		flag = true;

		//270‹
		rep(i, 0, S_right - S_left){
			rep(j, 0, S_bottom - S_top){
				if(S.at(S_bottom - j - 1).at(i + S_left) != T.at(i + T_top).at(j + T_left)) flag = false;
			}
		}

		if(flag) ans = true;
	}

	if(ans) Yes;
	else No;

	return 0;
}