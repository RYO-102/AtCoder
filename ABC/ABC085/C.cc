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
	//ABC085_C
	ll N, Y;
	cin >> N >> Y;

	rep(i, 0, N + 1){
		rep(j, 0, N + 1){
			ll balance = Y - (10000 * i) - (5000 * j);

			if(balance >= 0 && balance == 1000 * (N - i - j)){
				cout << i << ' ' << j << ' ' << (N - i - j) << '\n';
				return;
			}
		}
	}

	cout << "-1 -1 -1\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}