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
int N, M;
vector<string> S;

int main(){
	//ABC358 C
	cin >> N >> M;
	S.resize(N);
	rep(i, 0, N) cin >> S.at(i);

	int ans = 10;

	rep(bit, 0, (1 << N)){
		vector<int> visit;
		rep(i, 0, N){
			if(bit & (1 << i)){
				visit.push_back(i);
			}
		}

		vector<bool> flavor(M, false);

		rep(i, 0, visit.size()){
			rep(j, 0, M){
				if(S.at(visit.at(i)).at(j) == 'o') flavor.at(j) = true;
			}
		}

		bool flag = false;
		rep(i, 0, M){
			if(!flavor.at(i)) flag = true;
		}
		if(flag) continue;

		if(visit.size() <= ans) ans = visit.size();
	}

	cout << ans << endl;

	return 0;
}