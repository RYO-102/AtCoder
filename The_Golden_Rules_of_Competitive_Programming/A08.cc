#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

#define rep(i, begin, limit) for(ll i = (ll)begin; i < (ll)limit; i++)

void solve() {
	ll H, W, Q;
	if(!(cin >> H >> W)) return;
	vector<vector<ll>> X(H, vector<ll>(W));
	rep(i, 0, H){
		for(auto& j : X[i]) cin >> j;
	}
	if(!(cin >> Q)) return;

	vector<vector<ll>> two_dimentional_prefix_sum(H + 1, vector<ll>(W + 1, 0));
	rep(i, 0, H){
		rep(j, 0, W){
			two_dimentional_prefix_sum[i + 1][j + 1] = two_dimentional_prefix_sum[i + 1][j] + two_dimentional_prefix_sum[i][j + 1] - two_dimentional_prefix_sum[i][j] + X[i][j];
		}
	}

	rep(i, 0, Q){
		ll a, b, c, d;
		cin >> a >> b >> c >> d;

		cout << two_dimentional_prefix_sum[c][d] - two_dimentional_prefix_sum[c][b - 1] - two_dimentional_prefix_sum[a - 1][d] + two_dimentional_prefix_sum[a - 1][b - 1] << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}