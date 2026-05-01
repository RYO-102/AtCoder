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
	ll H, W;
	cin >> H >> W;
	vector<string> S(H);
	rep(i, 0, H) cin >> S[i];

	ll ans = 0;

	rep(h1, 0, H){
		rep(h2, h1, H){
			rep(w1, 0, W){
				rep(w2, w1, W){

					bool flag = true;

					rep(i, h1, h2 + 1){
						rep(j, w1, w2 + 1){
							if(S[i][j] != S[h1 + h2 - i][w1 + w2 - j]) flag = false;
						}
					}

					if(flag) ans++;

				}
			}
		}
	}

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}