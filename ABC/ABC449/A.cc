#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;

#define rep(i, begin, limit) for(ll i = (ll)begin; i < (ll)limit; i++)
#define rrep(i, begin, limit) for(ll i = (ll)begin; i > (ll)limit; i--)

const ll INF = 1LL << 60;

void solve() {
	//ABC449_A
	ll D;
	cin >> D;

	cout << fixed << setprecision(10) << acos(-1.0) * D * D / 4 << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}