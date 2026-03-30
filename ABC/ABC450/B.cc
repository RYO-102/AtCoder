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
	//ABC450_B
	ll N;
	cin >> N;
	vector<vector<ll>> C(N - 1, vector<ll>(N, -1));
	rep(i, 0, N - 1) rep(j, i + 1, N) cin >> C[i][j];

	bool exist = false;

	rep(a, 0, N){
		rep(b, a + 1, N){
			rep(c, b + 1, N){
				if(C[a][b] + C[b][c] < C[a][c]) exist = true;
			}
		}
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