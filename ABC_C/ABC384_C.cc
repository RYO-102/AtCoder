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
int a, b, c, d, e;

int main(){
	//ABC 384 C
	cin >> a >> b >> c >> d >> e;
	vector<int> point{a, b, c, d, e};

	vector<pair<int, string>> list(31);

	rep(bit, 1, (1 << 5)){
		int total = 0;
		string Problem = "ABCDE", name;
		rep(i, 0, 5){
			if(bit & (1 << i)){
				name += Problem.at(i);
				total += point.at(i);
			}
		}

		list.at(bit - 1) = make_pair(total, name);
	}

	sort(all(list));


	rirep(i, 30, 0){
		int pointer = i;
		while(pointer > 0 && list.at(pointer).first == list.at(pointer - 1).first){
			pointer--;
		}

		irep(j, pointer, i){
			cout << list.at(j).second << endl;
		}

		i = pointer;
	}

	return 0;
}