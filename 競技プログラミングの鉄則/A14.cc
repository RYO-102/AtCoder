#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

#define rep(i, begin, limit) for(ll i = (ll)begin; i < (ll)limit; i++)
#define rrep(i, begin, limit) for(ll i = (ll)begin; i > (ll)limit; i--)

void solve() {
	ll N, K;
	if(!(cin >> N >> K)) return;
	vector<ll> A(N), B(N), C(N), D(N);
	for(auto& i : A) if(!(cin >> i)) return;
	for(auto& i : B) if(!(cin >> i)) return;
	for(auto& i : C) if(!(cin >> i)) return;
	for(auto& i : D) if(!(cin >> i)) return;

	vector<ll> AB, CD;
	rep(i, 0, N){
		rep(j, 0, N){
			AB.push_back(A[i] + B[j]);
			CD.push_back(C[i] + D[j]);
		}
	}

	sort(AB.begin(), AB.end());
	sort(CD.begin(), CD.end());

	bool ans = false;
	for(auto& ab : AB){
		ans = binary_search(CD.begin(), CD.end(), K - ab);

		if(ans){
			cout << "Yes\n";
			return;
		}
	}

	cout << "No\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}