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
	//ABC449_B
	ll H, W, Q;
	cin >> H >> W >> Q;

	while(Q--){
		ll query;
		cin >> query;

		if(query == 1){
			ll R;
			cin >> R;

			cout << R * W << '\n';
			H -= R;
		}else{
			ll C;
			cin >> C;

			cout << H * C << '\n';
			W -= C;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}