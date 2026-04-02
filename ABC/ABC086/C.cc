#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

#define rep(i, begin, limit) for(ll i = (ll)begin; i < (ll)limit; i++)
#define rrep(i, begin, limit) for(ll i = (ll)begin; i > (ll)limit; i--)

const ll INF = 1LL << 60;

void solve() {
	//ABC086_C
	ll N;
	cin >> N;
	vector<ll> t(N), x(N), y(N);
	rep(i, 0, N) cin >> t[i] >> x[i] >> y[i];

	pair<ll, ll> locate = {0, 0};
	ll time = 0;

	rep(i, 0, N){
		ll balance = t[i] - time, mv_x = abs(x[i] - locate.first), mv_y = abs(y[i] - locate.second);

		if(balance < (mv_x + mv_y) || (balance - mv_x - mv_y) % 2 != 0){
			cout << "No\n";
			return;
		}else{
			time = t[i];
			locate = {x[i], y[i]};
		}
	}

	cout << "Yes\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}