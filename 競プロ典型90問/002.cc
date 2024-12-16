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
int N;

int main(){
	//競プロ典型90問 002
	cin >> N;

	vector<char> base_row(N);
	rep(i, 0, N){
		if(i < N / 2) base_row.at(i) = '(';
		else base_row.at(i) = ')';
	}

	bool ans = true;

	do{
		int left_parentheses = 0, right_parentheses = 0;

		rep(i, 0, N){
			if(base_row.at(i) == '(') left_parentheses++;
			else right_parentheses++;

			if(left_parentheses - right_parentheses < 0) ans = false;
		}

		if(ans){
			rep(i, 0, N){
				cout << base_row.at(i);
			}
			cout << endl;
		}

		ans = true;
	}while(next_permutation(all(base_row)));

	return 0;
}