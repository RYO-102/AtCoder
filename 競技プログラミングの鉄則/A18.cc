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
	ll N, S;
	if(!(cin >> N >> S)) return;
	vector<ll> A(N);
	for(auto& i : A) if(!(cin >> i)) return;

	vector<vector<bool>> dp(N + 1, vector<bool>(S + 1, false));
	dp[0][0] = true;

	rep(i, 0, N){
		rep(j, 0, S + 1){
			if(dp[i][j]) dp[i + 1][j] = true;
			if(j + A[i] <= S && dp[i][j]) dp[i + 1][j + A[i]] = true;
		}
	}

	if(dp[N][S]) cout << "Yes\n";
	else cout << "No\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}