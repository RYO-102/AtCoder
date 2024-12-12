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
	//ABC 147 C
	int N;
	cin >> N;
	vector<int> A(N);
	vector<vector<int>> x(N), y(N);
	rep(i, 0, N){
		cin >> A.at(i);
		rep(j, 0, A.at(i)){
			int tmp_x, tmp_y;
			cin >> tmp_x >> tmp_y;
			x.at(i).push_back(tmp_x);
			y.at(i).push_back(tmp_y);
		}
	}

	int ans = 0;

	rep(bit, 0, (1 << N)){
		int pre_ans = 0;
		vector<bool> honest(N, false);
		rep(i, 0, N){
			if(bit & (1 << i)){
				honest.at(i) = true;
				pre_ans++;
			}
		}

		bool correct = true;
		rep(i, 0, N){
			if(honest.at(i)){
				rep(j, 0, A.at(i)){
					int num = x.at(i).at(j), trueth = y.at(i).at(j);
					//正直者が正直者でないものを1という
					//正直者が正直者を0という
					if(trueth == 0 && honest.at(num - 1) || trueth == 1 && !honest.at(num - 1)){
						correct = false;
					}
				}
			}
		}

		//bitで1が立っている数だけ正直ものがいる
		if(ans < pre_ans && correct){
			ans = pre_ans;
		}		
	}

	cout << ans << endl;

	return 0;
}