#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;
using ll = long long;

#define rep(i, begin, limit) for(ll i = (ll)begin; i < (ll)limit; i++)
#define rrep(i, begin, limit) for(ll i = (ll)begin; i > (ll)limit; i--)

const ll INF = 1LL << 60;

void solve() {
	//ABC449_C
	ll N, L, R;
	string S;
	cin >> N >> L >> R >> S;

	ll ans = 0;
	map<char, ll> bucket;
	rep(i, L, R + 1) bucket[S[i]]++;
	
	rep(i, 0, N - L){
		ans += bucket[S[i]];

		bucket[S[i + L]]--;
		if(i + R + 1 < N) bucket[S[i + R + 1]]++;
	}

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}