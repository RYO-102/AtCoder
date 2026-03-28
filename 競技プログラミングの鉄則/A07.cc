#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

#define rep(i, begin, limit) for(ll i = (ll)begin; i < (ll)limit; i++)

void solve() {
	ll D, N;
	if(!(cin >> D >> N)) return;

	vector<ll> days(D + 1, 0);
	rep(i, 0, N){
		ll l, r;
		cin >> l >> r;
		days[--l]++;
		days[r]--;
	}

	ll participant = 0;

	rep(i, 0, D){
		participant += days[i];
		cout << participant << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}