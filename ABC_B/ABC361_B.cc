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
	//ABC 361 B
	vector<int> A(6), B(6);
	rep(i, 0, 6) cin >> A.at(i);
	rep(i, 0, 6) cin >> B.at(i);

	bool ans_x = false, ans_y = false, ans_z = false;

	rep(i, min(B.at(0), B.at(3)) + 1, max(B.at(0), B.at(3))){
		if(min(A.at(0), A.at(3)) <= i && i <= max(A.at(0), A.at(3))) ans_x = true;
	}

	rep(i, min(B.at(1), B.at(4)) + 1, max(B.at(1), B.at(4))){
		if(min(A.at(1), A.at(4)) <= i && i <= max(A.at(1), A.at(4))) ans_y = true;
	}

	rep(i, min(B.at(2), B.at(5)) + 1, max(B.at(2), B.at(5))){
		if(min(A.at(2), A.at(5)) <= i && i <= max(A.at(2), A.at(5))) ans_z = true;
	}

	if(ans_x && ans_y && ans_z) cout << "Yes" << endl;
	else cout << "No" << endl;
}