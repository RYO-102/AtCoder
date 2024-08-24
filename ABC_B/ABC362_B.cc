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
	//ABC 362 B
	double xa, ya, xb, yb, xc, yc;
	cin >> xa >> ya >> xb >> yb >> xc >> yc;

	double A = abs(pow((xb - xa), 2) + pow((yb - ya), 2));
	double B = abs(pow((xc - xb), 2) + pow((yc - yb), 2));
	double C = abs(pow((xa - xc), 2) + pow((ya - yc), 2));

	if(A + B == C || B + C == A || C + A == B) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}