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
	//ABC 212 B

	//入力が一個ずつだと思ったら繋がってた…
	//vector<int> X(4);
	//rep(i, 0, 4) cin >> X.at(i);

	int X;
	cin >> X;

	if((X == 0) || (X % 1111 == 0)) cout << "Weak" << endl;
	else{
		rep(i, 0, 3){
			int rank = X % 10 - 1;
			if(rank < 0) rank = 9;
			X /= 10;

			if(rank != X % 10){
				cout << "Strong" << endl;
				return 0;
			}
		}

		cout << "Weak" << endl;
	}
}