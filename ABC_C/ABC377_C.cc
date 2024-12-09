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

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using graph = vector<vector<int>>;

#define rep(i, begin, limit) for(ll i = (ll)begin; i < (ll)limit; i++)
#define irep(i, begin, limit) for(ll i = (ll)begin; i <= (ll)limit; i++)
#define rrep(i, begin, limit) for(ll i = (ll)begin; i > (ll)limit; i--)
#define rirep(i, begin, limit) for(ll i = (ll)begin; i >= (ll)limit; i--)
#define all(vec_name) vec_name.begin(), vec_name.end()
#define rall(vec_name) vec_name.rbegin(), vec_name.rend()

//sort(S.bigin(), S.end(), greater<int>())
//set<type> insert(n) erase(n) name.count(n)
//map<type,type> [key]=n erase(key)
//pair<type, type> .first .second
//vector<vector<int>> area(H, vector<int>(W, 0));
//順列 next_permutation(all(vector))

//sort O(NlogN)
//S.substr(開始位置, 取り出す長さ);
//int 最大値 2,147,483,647
//TLE目安 10^8がアウト

int main(){
	//ABC 377 C
	ll N, M;
	cin >> N >> M;
	vector<ll> A(M), B(M);
	rep(i, 0, M) cin >> A.at(i) >> B.at(i);

	ll ans = N * N;
	//vector<vector<bool>> seen(N, vector<bool>(N, false));
	set<pair<ll, ll>> seen;
	vector<ll> dx{-2, -1, 1, 2}, dy{-2, -1, 1, 2};

 	rep(i, 0, M){
		ll a = A.at(i) - 1, b = B.at(i) - 1;
		
		/*if(!seen.at(a).at(b)){
			seen.at(a).at(b) = true;
			ans--;
		}*/
		if(!seen.count(make_pair(a, b))){
			seen.insert(make_pair(a, b));
			ans--;
		}

		rep(j, 0, 4){
			rep(k, 0, 4){
				//条件を満たすか
				if(dx.at(j) + dy.at(k) == 0 || dx.at(j) - dy.at(k) == 0)
					continue;

				//移動できるかどうか
				if(a + dx.at(j) < 0 || N <= a + dx.at(j) || b + dy.at(k) < 0 || N <= b + dy.at(k))
					continue;

				//すでに探索したかどうか
				/*if(seen.at(a + dx.at(j)).at(b + dy.at(k)))
					continue;*/
				if(seen.count(make_pair(a + dx.at(j), b + dy.at(k))))
					continue;

				/*seen.at(a + dx.at(j)).at(b + dy.at(k)) = true;
				ans--;*/
				seen.insert(make_pair(a + dx.at(j), b + dy.at(k)));
				ans--;
			}
		}
	}

	cout << ans << endl;

	return 0;
}