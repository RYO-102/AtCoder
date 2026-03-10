#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

#define rep(i, begin, limit) for(ll i = (ll)begin; i < (ll)limit; i++)

ll calc_digit_sum(ll num){
	ll res = 0;
	
	while(num > 0){
		res += num % 10;
		num /= 10;
	}

	return res;
}

void solve() {
	ll N, K;
	if(!(cin >> N >> K)) return;

	ll ans = 0;
	rep(i, 1, N + 1){
		if(calc_digit_sum(i) == K) ans++;
	}

	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}