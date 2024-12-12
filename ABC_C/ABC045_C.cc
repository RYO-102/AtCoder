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

int main(){
	//ABC 045 C
	string S;
	cin >> S;

	ll ans = 0;

	rep(bit, 0, (1 << (S.length() - 1))){
		vector<bool> plus_locate(S.length(), false);
		
		rep(i, 0, S.length() - 1){
			if(bit & (1 << i)){
				plus_locate.at(i) = true;
			}
		}

		ll stock = S.at(0) - '0';
		rep(i, 0, S.length() - 1){
			if(plus_locate.at(i)){
				ans += stock;
				stock = S.at(i + 1) - '0';
			}else{
				stock *= 10;
				stock += S.at(i + 1) - '0';
			}
		}

		ans += stock;
	}

	cout << ans << endl;

	return 0;
}