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
int N, K;
vector<int> R;
vector<int> sub_combination;

void serch(int digit){

	irep(i, 1, R.at(digit)){
		sub_combination.at(digit) = i;

		if(digit == N - 1){
			int sum = 0;
			rep(j, 0, N) sum += sub_combination.at(j);

			if(sum % K == 0){
				rep(j, 0, N) cout << sub_combination.at(j) << ' ';
				cout << endl;
			}
		}else{
			serch(digit + 1);
		}
	}

	return;
}

int main(){
	//ABC 367 C
	cin >> N >> K;
	R.resize(N);
	rep(i, 0, N) cin >> R.at(i);

	int digit = 0;
	sub_combination.resize(N);

	serch(digit);

	return 0;
}