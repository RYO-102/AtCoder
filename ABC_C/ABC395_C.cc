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
ll N;
vector<ll> A;

int main(){
	//ABC395_C
	cin >> N;
	A.resize(N);
	rep(i, 0, N) cin >> A.at(i);

	vector<ll> locate(10000000, -1);
	ll ans = -1;

	rep(i, 0, N){
		if(locate.at(A.at(i) - 1) == -1){
			locate.at(A.at(i) - 1) = i;
		}else{
			if(ans == -1) ans = i - locate.at(A.at(i) - 1) + 1;
			else ans = min(i - locate.at(A.at(i) - 1) + 1, ans);

			locate.at(A.at(i) - 1) = i;
		}
	}

	cout << ans << endl;

	return 0;
}