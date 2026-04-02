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
	ll N, M;
	cin >> N >> M;
	vector<ll> A(M), B(M);
	rep(i, 0, M) cin >> A[i] >> B[i];

	vector<ll> bucket(N, 0);
	rep(i, 0, M){
		bucket[A[i] - 1]++;
		bucket[B[i] - 1]++;
	}

	rep(i, 0, N){
		ll nonrelocated = N - bucket[i] - 1;

		cout << nonrelocated * (nonrelocated - 1) * (nonrelocated - 2) / 6 << ' ';
	}

	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}