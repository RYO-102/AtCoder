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
ll N, M;
vector<ll> A;

int main(){
	//ABC365 C
	cin >> N >> M;
	A.resize(N);
	rep(i, 0, N) cin >> A.at(i);

	//�������̔��f
	ll total = 0;
	rep(i, 0, N) total += A.at(i);
	if(total <= M){
		cout << "infinite" << endl;
		return 0;
	}

	//�񕪒T��
	ll ok = 0, ng = M + 1, sum_budget = 0;

	while(abs(ok - ng) > 1){
		ll mid = (ok + ng) / 2;

		rep(i, 0, N){
			if(A.at(i) <= mid) sum_budget += A.at(i);
			else sum_budget += mid;
		}

		if(sum_budget <= M) ok = mid;
		else ng = mid;

		sum_budget = 0;
	}

	cout << ok << endl;

	return 0;
}