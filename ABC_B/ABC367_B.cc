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
#define rrep(i, bigin, limit) for(ll i = (ll)begin; i > (ll)limit; i--)
#define rirep(i, bigin, limit) for(ll i = (ll)begin; i >= (ll)limit; i--)
#define all(vec_name) vec_name.begin(), vec_name.end()
#define rall(vec_name) vec_name.rbegin(), vec_name.rend()

//sort(S.bigin(), S.end(), greater<int>())
//set<type> insert(n) erase(n)
//map<type,type> [key]=n erase(key)
//vector<vector<int>> area(H, vector<int>(W, 0));
//sort O(NlogN)
//S.substr(開始位置, 取り出す長さ);

int main(){
	//ABC 367 B
	double X;
	cin >> X;

	double integer = X / 1;
	cout << integer;
	X -= integer;

	if(X == 0) return 0;

	cout << '.';

	rep(i, 0, 3){
		X *= 10;
		integer = X / 1;
		cout << integer;

		X -= integer;

		if(X == 0) return 0;
	}
}