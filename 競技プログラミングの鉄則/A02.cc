#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

#define rep(i, begin, limit) for(ll i = (ll)begin; i < (ll)limit; i++)

void solve() {
	ll N, X;
	vector<ll> A;
	cin >> N >> X;
	A.resize(N);
	rep(i, 0, N) cin >> A[i];

	bool exist = false;

	rep(i, 0, N){
		if(A[i] == X) exist = true;
	}

	if(exist) cout << "Yes\n";
	else cout << "No\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}