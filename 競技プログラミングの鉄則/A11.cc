#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

#define rep(i, begin, limit) for(ll i = (ll)begin; i < (ll)limit; i++)

void solve() {
	ll N, X;
	if(!(cin >> N >> X)) return;
	vector<ll> A(N);
	for(auto& i : A){
		if(!(cin >> i)) return;
	}

	cout << lower_bound(A.begin(), A.end(), X) - A.begin() + 1 << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}