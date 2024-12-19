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

//宣言部
ll N;
vector<ll> L, R;

int main(){
	//ABC362 C
	cin >> N;
	L.resize(N);
	R.resize(N);
	rep(i, 0, N) cin >> L.at(i) >> R.at(i);

	ll min = 0, max = 0;
	vector<ll> ans(N);
	rep(i, 0, N){
		min += L.at(i);
		max += R.at(i);
		ans.at(i) = L.at(i);
	}

	//sum = 0に出来るかどうか
	if(min > 0 || max < 0){
		cout << "No" << endl;
		return 0;
	}else{
		cout << "Yes" << endl;
	}

	ll sum = min;
	rep(i, 0, N){
		sum -= L.at(i);
		sum += R.at(i);

		ll pre_mid = R.at(i), ok = L.at(i), ng = R.at(i) + 1;

		if(sum >= 0){
			while(abs(ok - ng) > 1){
				ll mid = (ok + ng) / 2;

				sum -= pre_mid;
				sum += mid;

				if(sum <= 0) ok = mid;
				else ng = mid;

				pre_mid = mid;
			}

			ans.at(i) = ok;
			break;
		}

		ans.at(i) = R.at(i);
	}

	rep(i, 0, N){
		cout << ans.at(i) << ' ';
	}
	cout << endl;

	return 0;
}