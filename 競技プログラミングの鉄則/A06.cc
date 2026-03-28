#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

#define rep(i, begin, limit) for(ll i = (ll)begin; i < (ll)limit; i++)

void solve() {
	ll N, Q;
	if(!(cin >> N >> Q)) return;
	vector<ll> A(N), L(Q), R(Q);
	for(auto& i : A) cin >> i;
	rep(i, 0, Q) cin >> L[i] >> R[i];

	vector<ll> prefix_sum(N + 1, 0);
	rep(i, 0, N) prefix_sum[i + 1] = prefix_sum[i] + A[i];
	
	rep(i, 0, Q) cout << prefix_sum[R[i]] - prefix_sum[L[i] - 1] << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}