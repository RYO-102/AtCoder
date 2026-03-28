#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

#define rep(i, begin, limit) for(ll i = (ll)begin; i < (ll)limit; i++)
#define rrep(i, begin, limit) for(ll i = (ll)begin; i > (ll)limit; i--)

void solve() {
	ll N, K;
	if(!(cin >> N >> K)) return;
	vector<ll> A(N);
	for(auto& i : A) if(!(cin >> i)) return;

	ll ans = 0, pos = 1;
	rep(i, 0, N - 1){
		while(pos < N && A[pos] - A[i] <= K) pos++;

		ans += (pos - 1 - i);
	}

	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}