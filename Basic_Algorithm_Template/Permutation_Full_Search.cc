/*
Permutation_Full_Search
https://atcoder.jp/contests/abc145/tasks/abc145_c
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<ll>;

#define rep(i, begin, limit) for(ll i = (ll)begin; i < (ll)limit; i++)
#define all(vec_name) vec_name.begin(), vec_name.end()
#define EuclideanDistance(X1, Y1, X2, Y2) sqrt((X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2))

//Declaration
ll N;
vll x, y;

int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	
	// “ü—Í
	cin >> N;
	x.resize(N), y.resize(N);
	rep(i, 0, N) cin >> x.at(i) >> y.at(i);

	// –K–â‡‚ğŠi”[‚·‚éƒxƒNƒ^[
	vll order(N);
	rep(i, 0, N) order.at(i) = i;

	ld total_dist = 0, count = 0;

	do{
		ld length = 0;

		// Œ»İ‚Ì‡—ñ‚É‘Î‚µ‚ÄŒo˜H’·‚ğŒvZ
		rep(i, 0, N - 1){
			ll from = order.at(i), to = order.at(i + 1);

			length += EuclideanDistance(x.at(from), y.at(from), x.at(to), y.at(to));
		}

		total_dist += length;
		count++;
	}while(next_permutation(all(order)));

	cout << fixed << setprecision(10) << (total_dist / count) << endl;

	return 0;
}