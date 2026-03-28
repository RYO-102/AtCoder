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
	string S, T;
	if(!(cin >> S >> T)) return;

	vector<vector<ll>> dp(S.length() + 1, vector<ll>(T.length() + 1, 0));
	rep(i, 1, S.length() + 1){
		rep(j, 1, T.length() + 1){
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

			if(S[i - 1] == T[j - 1]){
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
			}
		}
	}

	cout << dp[S.length()][T.length()] << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}