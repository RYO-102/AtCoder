#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

#define rep(i, begin, limit) for(ll i = (ll)begin; i < (ll)limit; i++)
#define rrep(i, begin, limit) for(ll i = (ll)begin; i > (ll)limit; i--)

const ll INF = 1LL << 60;

void solve() {
	ll N, W;
	if(!(cin >> N >> W)) return;

	vector<vector<ll>> dp(N + 1, vector<ll>(W + 1, 0));
	rep(i, 1, N + 1){
		ll w, v;
		if(!(cin >> w >> v)) return;

		rep(j, 0, W + 1){
			if(j - w < 0){
				dp[i][j] = dp[i - 1][j];
			}else{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + v);
			}
		}
	}

	cout << dp[N][W] << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}