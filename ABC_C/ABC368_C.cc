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
#include <climits>

using namespace std;
using ll = long long;
using ull = unsigned long long;

#define rep(i, begin, limit) for(ll i = (ll)begin; i < (ll)limit; i++)
#define irep(i, begin, limit) for(ll i = (ll)begin; i <= (ll)limit; i++)
#define rrep(i, begin, limit) for(ll i = (ll)begin; i > (ll)limit; i--)
#define rirep(i, begin, limit) for(ll i = (ll)begin; i >= (ll)limit; i--)
#define all(vec_name) vec_name.begin(), vec_name.end()
#define rall(vec_name) vec_name.rbegin(), vec_name.rend()

//sort(S.bigin(), S.end(), greater<int>())
//set<type> insert(n) erase(n)
//map<type,type> [key]=n erase(key)
//vector<vector<int>> area(H, vector<int>(W, 0));

//sort O(NlogN)
//S.substr(開始位置, 取り出す長さ);

int main(){
	//ABC 368 C
	ll N;
	cin >> N;
	vector<ll> H(N);
	rep(i, 0, N) cin >> H.at(i);

	ll T = 0;
	ll enemy_num = 0;

	while(H.at(N - 1) > 0){
		T++;

		if(H.at(enemy_num) >= 5){
			int damage = H.at(enemy_num) / 5;
			H.at(enemy_num) %= 5;
			T += damage * 3 - 1;
		}else{
			if(T % 3 == 0){
				H.at(enemy_num) -= 3;
			}else{
				H.at(enemy_num)--;
			}
		}

		/*if(T % 3 == 0){
			H.at(enemy_num) = H.at(enemy_num) - 3;
		}else{
			H.at(enemy_num) = H.at(enemy_num) - 2;
			T++;
		}*/

		if(H.at(enemy_num) <= 0) enemy_num++;
	}

	cout << T << endl;
}