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
	//ABC 080 C
	int N;
	cin >> N;
	vector<vector<int>> F(N, vector<int>(10));
	rep(i, 0, N){
		rep(j, 0, 10){
			cin >> F.at(i).at(j);
		}
	}
	vector<vector<int>> P(N, vector<int>(11));
	rep(i, 0, N){
		rep(j, 0, 11){
			cin >> P.at(i).at(j);
		}
	}

	int ans = INT_MIN;

	rep(bit, 1, (1 << 10)){
		vector<int> open(10, false);
		rep(i, 0, 10){
			if(bit & (1 << i)){
				open.at(i) = true;
			}
		}

		int benefit = 0;
		rep(i, 0, N){
			int count = 0;
			
			rep(j, 0, 10){
				if(F.at(i).at(j) == 1 && open.at(j)) count++;
			}

			benefit += P.at(i).at(count);
		}

		if(ans < benefit) ans = benefit;
	}

	cout << ans << endl;

	return 0;
}