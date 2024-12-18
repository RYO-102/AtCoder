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
ll N, K;
vector<ll> A;

int main(){
	//ABC361 C
	cin >> N >> K;
	A.resize(N);
	rep(i, 0, N) cin >> A.at(i);

	if(N - K  == 1){
		cout << 0 << endl;
		return 0;
	}

	sort(all(A));
	vector<ll> B;
	ll min_pointer = 0, max_pointer = N - K - 1;

	while(max_pointer < N){
		B.push_back(A.at(max_pointer) - A.at(min_pointer));
		max_pointer++;
		min_pointer++;
	}

	sort(all(B));
	cout << B.at(0) << endl;

	return 0;
}