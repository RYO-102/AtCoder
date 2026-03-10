#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

#define rep(i, begin, limit) for(ll i = (ll)begin; i < (ll)limit; i++)

void solve() {
	ll H, W, N;
	if(!(cin >> H >> W >> N)) return;

	vector<vector<ll>> snow(H + 1, vector<ll>(W + 1, 0));
	rep(i, 0, N){
		ll a, b, c, d;
		cin >> a >> b >> c >> d;

		snow[a - 1][b - 1]++;
		snow[a - 1][d]--;
		snow[c][b - 1]--;
		snow[c][d]++;
	}

	//横方向の累積
	rep(i, 0, H + 1){
		rep(j, 0, W){
			snow[i][j + 1] += snow[i][j];
		}
	}

	//縦方向の累積
	rep(j, 0, W + 1){
		rep(i, 0, H){
			snow[i + 1][j] += snow[i][j];
		}
	}

	rep(i, 0, H){
		rep(j, 0, W){
			cout << snow[i][j] << ' ';
		}
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}