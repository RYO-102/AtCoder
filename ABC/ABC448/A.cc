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
	//ABC448_A
	ll N, X;
	cin >> N >> X;
	vector<ll> A(N);
	rep(i, 0, N) cin >> A[i];

	rep(i, 0, N){
		if(A[i] < X){
			X = A[i];
			cout << "1\n";
		}else{
			cout << "0\n";
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}