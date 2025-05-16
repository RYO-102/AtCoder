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
vll A, B, C, D;

int main(){
	//ABC232_C
	cin >> N >> M;
	A.resize(M), B.resize(M), C.resize(M), D.resize(M);
	rep(i, 0, M) cin >> A.at(i) >> B.at(i);
	rep(i, 0, M) cin >> C.at(i) >> D.at(i);

	vll order(N);
	rep(i, 0, N) order.at(i) = i + 1;

	bool ans = false;

	do{
		bool isomorphism = true;

		rep(i, 0, M){
			ll Pi = order.at(A.at(i) - 1), Pj = order.at(B.at(i) - 1);
			bool connect = false;

			rep(j, 0, M){
				if((Pi == C.at(j) && Pj == D.at(j)) || (Pi == D.at(j) && Pj == C.at(j))) connect = true;
			}

			if(!connect) isomorphism = false;
		}

		if(isomorphism) ans = true;
	}while(next_permutation(all(order)));

	if(ans) Yes;
	else No;

	return 0;
}