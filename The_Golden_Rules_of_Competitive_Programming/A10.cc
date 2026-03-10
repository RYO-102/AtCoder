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
	vector<ll> A(N);
	for(auto& i : A) cin >> i;
	
	vector<ll> A_max_BtoE(N + 1, 0), A_max_EtoB(N + 1, 0);
	rep(i, 0, N) A_max_BtoE[i + 1] = max(A_max_BtoE[i], A[i]);
	rrep(i, N - 1, -1) A_max_EtoB[i] = max(A_max_EtoB[i + 1], A[i]);

	ll D;
	if(!(cin >> D)) return;
	
	rep(i, 0, D){
		ll l, r;
		if(!(cin >> l >> r)) return;

		cout << max(A_max_BtoE[l - 1], A_max_EtoB[r]) << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}