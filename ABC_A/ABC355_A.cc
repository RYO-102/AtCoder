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

int main(){
	//ABC 355 A
	int A, B;
	cin >> A >> B;

	int ans = -1;
	int min_num = min(A, B);
	int max_num = max(A, B);

	if(min_num == 1){
		if(max_num == 2){
			ans = 3;
		}else if(max_num == 3){
			ans = 2;
		}
	}else if(min_num == 2){
		if(max_num ==3){
			ans = 1;
		}
	}

	cout << ans << endl;
}