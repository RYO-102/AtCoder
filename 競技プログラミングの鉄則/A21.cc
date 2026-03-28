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
	ll N;
	cin >> N;
	vector<ll> P(N), A(N);
	rep(i, 0, N) cin >> P[i] >> A[i];

	vector<vector<ll>> dp(N + 1, vector<ll>(N + 1, -1));
	

	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}