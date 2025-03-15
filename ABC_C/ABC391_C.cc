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

//éŒ¾•”
ll N, Q;

int main(){
	//ABC391_C
	cin >> N >> Q;

	vector<ll> bird(N), nest(N, 1);
	rep(i, 0, N) bird.at(i) = i + 1;
	ll counter = 0;

	rep(i, 0, Q){
		int query;
		cin >> query;

		if(query == 1){
			ll P, H;
			cin >> P >> H;

			bool not_lonly = false;
			bool lonly = false;

			//‘ƒˆÚ“®‘O
			if(nest.at(bird.at(P - 1) - 1) >= 2) not_lonly = true;
			if(nest.at(H - 1) == 1) lonly = true;

			nest.at(bird.at(P - 1) - 1)--;

			if(not_lonly && nest.at(bird.at(P - 1) - 1) == 1) counter--;

			//”µ”z—ñ
			bird.at(P - 1) = H;

			//‘ƒˆÚ“®Œã
			nest.at(bird.at(P - 1) - 1)++;

			if(lonly && nest.at(bird.at(P - 1) - 1) >= 2) counter++;
		}else if(query == 2){
			cout << counter << endl;
		}
	}

	return 0;
}