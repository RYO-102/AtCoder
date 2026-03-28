#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

#define rep(i, begin, limit) for(ll i = (ll)begin; i < (ll)limit; i++)

void solve() {
	ll N;
	cin >> N;

	vector<int> bin_digit(10, 0);

	rep(i, 0, 10){
		bin_digit[i] = N % 2;
		N /= 2;

		if(N == 0) break;
	}

	for(ll i = 9; i >= 0; i--) cout << bin_digit[i];
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}