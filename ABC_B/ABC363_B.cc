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
#define all(vec_name) vec_name.begin(), vec_name.end()
#define rall(vec_name) vec_name.rbegin(), vec_name.rend()

//sort(S.bigin(), S.end(), greater<int>())
//set<type> insert(n) erase(n)
//map<type,type> [key]=n erase(key)
//vector<vector<int>> area(H, vector<int>(W, 0));
//sort O(NlogN)
//S.substr(開始位置, 取り出す長さ);

int main(){
	//ABC 363 B
	int N, T, P;
	cin >> N >> T >> P;
	vector<int> L(N);
	rep(i, 0, N) cin >> L.at(i);

	int days = 0;
	int count = 0;

	do{
		rep(i, 0, N){
			if(L.at(i) >= T) count++;
		}

		if(count >= P) break;

		count = 0;
		days++;
		rep(i, 0, N){
			L.at(i)++;
		}

	}while(1);

	cout << days << endl;
}