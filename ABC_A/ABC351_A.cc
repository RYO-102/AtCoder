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
	//ABC 351 A
	int A_sum = 0, B_sum = 0;
	rep(i, 0, 9){
		int A_point;
		cin >> A_point;
		A_sum += A_point;
	}
	rep(i, 0, 8){
		int B_point;
		cin >> B_point;
		B_sum += B_point;
	}

	cout << A_sum - B_sum + 1 << endl;
}