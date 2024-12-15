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
//���� next_permutation(all(vector))

//sort O(NlogN)
//S.substr(�J�n�ʒu, ���o������);
//int �ő�l 2,147,483,647
//TLE�ڈ� 10^8���A�E�g

//�錾��
ll N;
vector<ll> A;

int main(){
	//ABC 369 C
	cin >> N;
	A.resize(N);
	rep(i, 0, N) cin >> A.at(i);

	vector<ll> distance(N - 1);

	rep(i, 0, N - 1){
		distance.at(i) = A.at(i + 1) - A.at(i);
	}

	ll succession = 0, ans = N;

	rep(i, 0, N - 1){
		succession++;

		if(i != N - 2 && distance.at(i) == distance.at(i + 1)) continue;

		ans += succession * (succession + 1) / 2;
		succession = 0;
	}

	cout << ans << endl;

	return 0;
}