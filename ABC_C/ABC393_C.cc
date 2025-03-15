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
//using graph = vector<vector<int>>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i, begin, limit) for(ll i = (ll)begin; i < (ll)limit; i++)
#define rrep(i, begin, limit) for(ll i = (ll)begin; i > (ll)limit; i--)
#define all(vec_name) vec_name.begin(), vec_name.end()
#define rall(vec_name) vec_name.rbegin(), vec_name.rend()
#define vvec(type) vector<vector<type>>

const long long ll_INF = 1LL << 60;

//Declaration
ll N, M;
vector<pair<ll, ll>> graph;

int main(){
	//ABC393_B
	cin >> N >> M;
	graph.resize(M);
	rep(i, 0, M){
		ll u, v;
		cin >> u >> v;
		graph.at(i) = {u, v};
	}

	ll ans = 0;
	set<pair<ll, ll>> bucket;

	for(auto p : graph){
		if(p.first == p.second) ans++;
		else{
			if(bucket.count({p.first, p.second}) || bucket.count({p.second, p.first})){
				ans++;
			}else{
				bucket.insert({p.first, p.second});
				bucket.insert({p.second, p.first});
			}
		}
	}

	cout << ans << endl;

	return 0;
}