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
ll N, L, K;
vector<ll> A;

int main(){
	//���v���T�^90�� 001
	cin >> N >> L >> K;
	A.resize(N);
	rep(i, 0, N) cin >> A.at(i);

	ll ok = 0, ng = L + 1;

	while(abs(ok - ng) > 1){
		ll mid = (ok + ng) / 2;

		//��������greedy�@
		ll pre_cut = 0, score_count = 0;
		rep(i, 0, N){
			if(A.at(i) - pre_cut >= mid){
				score_count++;
				pre_cut = A.at(i);
			}

			if(i == N - 1 && L - pre_cut >= mid){
				score_count++;
			}
		}

		if(score_count >= K + 1){
			ok = mid;
		}else{
			ng = mid;
		}
	}

	cout << ok << endl;

	return 0;
}