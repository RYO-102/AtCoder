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
ll H, W;
vector<vector<char>> G;

int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

	//ABC265_C
	cin >> H >> W;
	G.resize(H, vector<char>(W));
	rep(i, 0, H) rep(j, 0, W) cin >> G.at(i).at(j);

	pll pos = make_pair(0, 0);
	set<pll> visited;
	bool stop = false;

	while(!visited.count(pos)){
		visited.insert(pos);

		ll *y = &pos.first, *x = &pos.second;

		switch(G.at(*y).at(*x)){
		case 'U':
			if(*y > 0) (*y)--;
			else stop = true;

			break;
		case 'D':
			if(*y < H - 1) (*y)++;
			else stop = true;

			break;
		case 'L':
			if(*x > 0) (*x)--;
			else stop = true;

			break;
		case 'R':
			if(*x < W - 1) (*x)++;
			else stop = true;

			break;
		}
	}

	if(stop) cout << pos.first + 1 << ' ' << pos.second + 1 << endl;
	else cout << -1 << endl;

	return 0;
}