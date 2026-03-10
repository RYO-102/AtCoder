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
	ll N;
	if(!(cin >> N)) return;
	vector<ll> P(N), A(N);
	rep(i, 0, N) if(!(cin >> P[i] >> A[i])) return;

	for(auto& p : P) p--;

	ll ans = 0;
	vector<bool> removed(N, false);
	map<pair<ll, ll>, bool> memo;

	auto dfs = [&](auto self, ll left, ll right, ll point) -> void{
		//終了条件
		if(left == right || memo[make_pair(left, right)]){
			ans = max(ans, point);
			return;
		}
		
		//左を取る
		removed[left] = true;
		if(!removed[P[left]]) point += A[left];
		
		self(self, left + 1, right, point);

		if(!removed[P[left]]) point -= A[left];
		removed[left] = false;

		//右を取る
		removed[right] = true;
		if(!removed[P[right]]) point += A[right];
		
		self(self, left, right - 1, point);

		if(!removed[P[right]]) point -= A[right];
		removed[right] = false;

		//メモ
		memo[make_pair(left, right)] = true;
	};

	dfs(dfs, 0, N - 1, 0);

	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}