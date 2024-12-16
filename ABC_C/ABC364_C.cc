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
ll N, X, Y;
vector<ll> A, B;

int main(){
	//ABC364 C
	cin >> N >> X >> Y;
	A.resize(N);
	B.resize(N);
	rep(i, 0, N) cin >> A.at(i);
	rep(i, 0, N) cin >> B.at(i);

	ll sweet_count = 0, salty_count = 0;
	sort(rall(A)); sort(rall(B));

	rep(i, 0, N){
		sweet_count += A.at(i);
		salty_count += B.at(i);

		if(sweet_count > X || salty_count > Y || i == N - 1){
			cout << i + 1 << endl;
			break;
		}
	}
	
	return 0;
}