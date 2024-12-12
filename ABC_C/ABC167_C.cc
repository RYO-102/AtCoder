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
	//ABC 167 C
	int N, M, X;
	cin >> N >> M >> X;
	vector<int> C(N);
	vector<vector<int>> A(N, vector<int>(M));
	rep(i, 0, N){
		cin >> C.at(i);
		rep(j, 0, M){
			cin >> A.at(i).at(j);
		}
	}

	int ans = -1;

	rep(bit, 0, (1 << N)){
		vector<bool> buying(N, false);
		rep(i, 0, N){
			if(bit & (1 << i)){
				buying.at(i) = true;
			}
		}

		int price = 0;
		vector<int> skills(M, 0);

		rep(i, 0, N){
			if(buying.at(i)){
				price += C.at(i);

				rep(j, 0, M){
					skills.at(j) += A.at(i).at(j);
				}
			}
		}

		bool correct = true;
		rep(i, 0, M){
			if(skills.at(i) < X) correct = false;
		}

		if(correct){
			if(ans > price || ans == -1) ans = price;
		}
	}

	cout << ans << endl;

	return 0;
}