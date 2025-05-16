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
#include <ctime>
#include <functional>
#include <cassert>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using sll = set<ll>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i, begin, limit) for(ll i = (ll)begin; i < (ll)limit; i++)
#define rrep(i, begin, limit) for(ll i = (ll)begin; i > (ll)limit; i--)
#define all(vec_name) vec_name.begin(), vec_name.end()
#define rall(vec_name) vec_name.rbegin(), vec_name.rend()
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define EuclideanDistance(X1, Y1, X2, Y2) sqrt((X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2))

const ll llINF = 1LL << 60;
const int intINF = 1073741823;

const vector<ll> dy{-1, 0, 1, 0}, dx{0, 1, 0, -1};
//const vector<ll> dy{-1, -1, 0, 1, 1, 1, 0, -1}, dx{0, 1, 1, 1, 0, -1, -1, -1};

//Declaration
ll N, M;
vector<vector<char>> A;

int main(){
	//ABC222_C
	cin >> N >> M;
	A.resize(2 * N, vector<char>(M));
	rep(i, 0, 2 * N) rep(j, 0, M) cin >> A.at(i).at(j);

	vector<pll> win(2* N);
	rep(i, 0, 2 * N) win.at(i) = make_pair(i, 0);

	rep(i, 0, M){
		rep(j, 1, N + 1){
			if(A.at(win.at(2 * j - 2).first).at(i) == A.at(win.at(2 * j - 1).first).at(i)) continue;

			if(A.at(win.at(2 * j - 2).first).at(i) == 'G'){
				if(A.at(win.at(2 * j - 1).first).at(i) == 'C') win.at(2 * j - 2).second++;
				else win.at(2 * j - 1).second++;
			}else if(A.at(win.at(2 * j - 2).first).at(i) == 'C'){
				if(A.at(win.at(2 * j - 1).first).at(i) == 'P') win.at(2 * j - 2).second++;
				else win.at(2 * j - 1).second++;
			}else{
				if(A.at(win.at(2 * j - 1).first).at(i) == 'G') win.at(2 * j - 2).second++;
				else win.at(2 * j - 1).second++;
			}
		}

		sort(all(win), [&](pll a, pll b){
			if(a.second != b.second){
				return a.second > b.second;
			}else{
				return a.first < b.first;
			}
		});
	}

	rep(i, 0, 2 * N) cout << win.at(i).first + 1 << endl;

	return 0;
}