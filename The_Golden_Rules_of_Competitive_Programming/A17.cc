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
	ll N;
	if(!(cin >> N)) return;
	vector<ll> A(N - 1), B(N - 2);
	for(auto& i : A) if(!(cin >> i)) return;
	for(auto& i : B) if(!(cin >> i)) return;

	vector<ll> dp(N, INF);
	dp[0] = 0;
	dp[1] = A[0];

	string pre_path = "1", suf_path = "1 2";
	ll pre_step = 1, suf_step = 2; 

	rep(i, 2, N){
		if(dp[i - 1] + A[i - 1] <= dp[i - 2] + B[i - 2]){
			dp[i] = dp[i - 1] + A[i - 1];
			
			pre_path = suf_path;
			suf_path += (" " + to_string(i + 1));
			pre_step = suf_step;
			suf_step++;
		}else{
			dp[i] = dp[i - 2] + B[i - 2];
			
			pre_path += (" " + to_string(i + 1));
			swap(pre_path, suf_path);
			pre_step++;
			swap(pre_step, suf_step);
		}
	}

	cout << suf_step << "\n" << suf_path << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}