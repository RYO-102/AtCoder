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
ll H1, W1, H2, W2;
vvll A, B;

int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

	//ABC264_C
	cin >> H1 >> W1;
	A.resize(H1, vll(W1));
	rep(i, 0, H1) rep(j, 0, W1) cin >> A.at(i).at(j);
	cin >> H2 >> W2;
	B.resize(H2, vll(W2));
	rep(i, 0, H2) rep(j, 0, W2) cin >> B.at(i).at(j);

	bool ans = false;

	// 2^N通りの部分集合を全探索
	rep(bit, 0, (1 << H1)){
		vll remain_line;

		// 各ビットに対応する要素を選ぶかどうか
		rep(i, 0, H1){
			if(bit & (1 << i)) remain_line.push_back(i);
		}

		rep(bit_sec, 0, (1 << W1)){
			vll remain_row;

			rep(i, 0, W1){
				if(bit_sec & (1 << i)) remain_row.push_back(i);
			}

			vvll temp_B(remain_line.size(), vll(remain_row.size()));

			rep(i, 0, remain_line.size()){
				rep(j, 0, remain_row.size()) temp_B.at(i).at(j) = A.at(remain_line.at(i)).at(remain_row.at(j));
			}

			if(temp_B == B) ans = true;
		}	
	}

	if(ans) Yes;
	else No;

	return 0;
}