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

int main(){
	//ABC 128 C
	int N, M;
	cin >> N >> M;
	vector<int> k(M);
	vector<vector<int>> s(M);
	rep(i, 0, M){
		cin >> k.at(i);
		rep(j, 0, k.at(i)){
			int tmp;
			cin >> tmp;
			s.at(i).push_back(tmp);
		}
	}
	vector<int> p(M);
	rep(i, 0, M) cin >> p.at(i);

	int ans = 0;

	rep(bit, 0, (1 << N)){
		vector<bool> on(N, false);
		rep(i, 0, N){
			if(bit & (1 << i)){
				on.at(i) = true;
			}
		}

		bool all_frash = true;
		rep(i, 0, M){
			int total = 0;
			for(int j : s.at(i)){
				if(on.at(j - 1)) total++;
			}

			if(total % 2 != p.at(i)) all_frash = false;
		}

		if(all_frash) ans++;
	}

	cout << ans << endl;

	return 0;
}