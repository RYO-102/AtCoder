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
using pll = pair<ll, ll>;
using graph = vector<vector<int>>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i, begin, limit) for(ll i = (ll)begin; i < (ll)limit; i++)
#define rrep(i, begin, limit) for(ll i = (ll)begin; i > (ll)limit; i--)
#define all(vec_name) vec_name.begin(), vec_name.end()
#define rall(vec_name) vec_name.rbegin(), vec_name.rend()
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl

const ll INFL = 1LL << 60;
const int INF = 1073741823;

const vector<ll> dy{-1, 0, 1, 0}, dx{0, 1, 0, -1};
//const vector<ll> dy{-1, -1, 0, 1, 1, 1, 0, -1}, dx{0, 1, 1, 1, 0, -1, -1, -1};

//Declaration
ll N, M;
vector<ll> B, W;

int main(){
	//ABC396_C
	cin >> N >> M;
	B.resize(N), W.resize(M);
	rep(i, 0, N) cin >> B.at(i);
	rep(i, 0, M) cin >> W.at(i);

	sort(rall(B)), sort(rall(W));

	ll ans = 0;

	rep(i, 0, N){
		if(i < M){
			if(B.at(i) > 0 && W.at(i) > 0) ans += (B.at(i) + W.at(i));
			else if(B.at(i) > 0) ans += B.at(i);
			else if(B.at(i) + W.at(i) > 0) ans += (B.at(i) + W.at(i));
		}else{
			if(B.at(i) > 0) ans += B.at(i);
		}
	}

	cout << ans << endl;

	return 0;
}