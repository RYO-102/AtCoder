//#include <bits/stdc++.h>
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
#define rrep(i, begin, limit) for(ll i = (ll)begin; i > (ll)limit; i--)
#define all(vec_name) vec_name.begin(), vec_name.end()
#define rall(vec_name) vec_name.rbegin(), vec_name.rend()

//êÈåæïî
int H, W;
vector<string> S;

int main(){
	//ABC390_C
	cin >> H >> W;
	S.resize(H);
	rep(i, 0, H) cin >> S.at(i);

	int left = 1000, right = -1, top = 1000, bottom = -1;
	
	rep(i, 0, H){
		rep(j, 0, W){
			if(S.at(i).at(j) == '#'){
				if(left > j) left = j;
				if(right < j) right = j;
				if(top > i) top = i;
				if(bottom < i) bottom = i;
			}
		}
	}

	bool ans = true;

	rep(i, top, bottom + 1){
		rep(j, left, right + 1){
			if(S.at(i).at(j) == '.') ans = false;
		}
	}

	cout << (ans ? "Yes" : "No") << endl;

	return 0;
}