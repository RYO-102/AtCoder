#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;
using ll = long long;

#define rep(i, begin, limit) for(ll i = (ll)begin; i < (ll)limit; i++)
#define rrep(i, begin, limit) for(ll i = (ll)begin; i > (ll)limit; i--)

const ll INF = 1LL << 60;

void solve() {
	//ABC448_C
	ll N, Q;
	cin >> N >> Q;
	vector<ll> A(N);
	rep(i, 0, N) cin >> A[i];

	vector<ll> A_sorted = A;
	sort(A_sorted.begin(), A_sorted.end());

	while(Q--){
		ll K;
		cin >> K;
		vector<ll> B(K);
		rep(i, 0, K) cin >> B[i];

		vector<ll> removed(K);
		rep(i, 0, K) removed[i] = A[B[i] - 1];
		sort(removed.begin(), removed.end());

		rep(i, 0, K + 1){
			if(i == K || A_sorted[i] != removed[i]){
				cout << A_sorted[i] << '\n';
				break;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}