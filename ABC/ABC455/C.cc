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
	ll N, K;
	cin >> N >> K;
	vector<ll> A(N);
	rep(i, 0, N) cin >> A[i];

	map<ll, ll> bucket;
	rep(i, 0, N){
		if(bucket[A[i]] == 0) bucket[A[i]] = A[i];
		else bucket[A[i]] += A[i];
	}

	vector<ll> sum_num;
	for(pair<ll, ll> p : bucket) sum_num.push_back(p.second);
	sort(sum_num.begin(), sum_num.end());

	ll ans = 0;
	rep(i, 0, sum_num.size() - K) ans += sum_num[i];

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}