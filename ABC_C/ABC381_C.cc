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

int count_length(int mid, string S){
	int pre_ans = 1, one_flag = mid, two_flag = mid;

	while(--one_flag >= 0 && ++two_flag < S.length() && S.at(one_flag) == '1' && S.at(two_flag) == '2'){
		pre_ans += 2;
	}

	return pre_ans;
}

int main(){
	//ABC 381 C
	int N;
	string S;
	cin >> N >> S;

	int ans = 0;
	vector<int> locate;

	rep(i, 0, N){
		if(S.at(i) == '/') locate.push_back(i);
	}

	rep(i, 0, locate.size()){
		ans = max(ans, count_length(locate.at(i), S));
	}

	cout << ans << endl;

	return 0;
}