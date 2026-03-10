#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

#define rep(i, begin, limit) for(ll i = (ll)begin; i < (ll)limit; i++)

void solve() {
	ll N, K;
	cin >> N >> K;

	ll ans = 0;

	rep(red, 1, N + 1){
		rep(blue, 1, N + 1){
			ll white = K - red - blue;

			if(1 <= white && white <= N) ans++;
		}
	}

	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}