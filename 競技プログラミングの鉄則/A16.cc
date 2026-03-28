#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

#define rep(i, begin, limit) for(ll i = (ll)begin; i < (ll)limit; i++)
#define rrep(i, begin, limit) for(ll i = (ll)begin; i > (ll)limit; i--)

void solve() {
	ll N;
	if(!(cin >> N)) return;
	vector<ll> A(N - 1), B(N - 2);
	for(auto& i : A) if(!(cin >> i)) return;
	for(auto& i : B) if(!(cin >> i)) return;

	vector<ll> dp(N, 0);
	dp[1] = A[0];
	rep(i, 2, N) dp[i] = min(dp[i - 1] + A[i - 1], dp[i - 2] + B[i - 2]);

	cout << dp[N - 1] << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}