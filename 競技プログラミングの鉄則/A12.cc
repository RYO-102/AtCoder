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
	vector<ll> A(N);
	for(auto& i : A) if(!(cin >> i)) return;

	sort(A.begin(), A.end());

	ll ok = 1000000000, ng = 0;
	while(abs(ok - ng) > 1){
		ll mid = (ok + ng) / 2, paper = 0;
		
		for(auto& a : A) paper += (mid / a);
		
		if(paper >= K) ok = mid;
		else ng = mid;
	}

	cout << ok << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}