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
	//ABC448_B
	ll N, M;
	cin >> N >> M;
	vector<ll>	C(M), A(N), B(N);
	rep(i, 0, M) cin >> C[i];
	rep(i, 0, N) cin >> A[i] >> B[i];

	ll ans = 0;

	rep(i, 0, N){
		ans += min(C[A[i] - 1], B[i]);
		C[A[i] - 1] = max((ll)0, C[A[i] - 1] - B[i]);
	}

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}