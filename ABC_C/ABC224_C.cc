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
ll N;
vector<ld> X, Y;

int main(){
	//ABC224_C
	cin >> N;
	X.resize(N), Y.resize(N);
	rep(i, 0, N) cin >> X.at(i) >> Y.at(i);

	ll ans = 0;

	rep(i, 0, N - 2){
		rep(j, i + 1, N - 1){
			rep(k, j + 1, N){
				//�[�����Z�΍�
				if(X.at(i) == X.at(j) && X.at(j) == X.at(k)) continue;

				if((Y.at(j) - Y.at(i)) / (X.at(j) - X.at(i)) == (Y.at(k) - Y.at(i)) / (X.at(k) - X.at(i))) continue;

				ans++;
			}
		}
	}

	cout << ans << endl;

	return 0;
}