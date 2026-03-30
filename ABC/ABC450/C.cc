#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;

#define rep(i, begin, limit) for(ll i = (ll)begin; i < (ll)limit; i++)
#define rrep(i, begin, limit) for(ll i = (ll)begin; i > (ll)limit; i--)

const ll INF = 1LL << 60;
const vector<ll> dy = {-1, 0, 1, 0}, dx = {0, 1, 0, -1};

void solve() {
	//ABC450_C
	ll H, W;
	cin >> H >> W;
	vector<vector<char>> S(H, vector<char>(W));
	rep(i, 0, H) rep(j, 0, W) cin >> S[i][j];

	vector<vector<bool>> checked(H, vector<bool>(W, false));
	ll ans = 0;

	rep(i, 0, H){
		rep(j, 0, W){
			if(S[i][j] == '.' && !checked[i][j]){
				bool surrounded = true;
				queue<pair<ll, ll>> q;
				q.push(make_pair(i, j));
				checked[i][j] = true;

				while(!q.empty()){
					ll y = q.front().first, x = q.front().second;
					q.pop();

					if(y == 0 || y == H - 1 || x == 0 || x == W - 1) surrounded = false;

					rep(k, 0, 4){
						ll yy = y + dy[k], xx = x + dx[k];

						if(yy < 0 || H <= yy || xx < 0 || W <= xx || S[yy][xx] == '#' || checked[yy][xx]) continue;
						else{
							q.push(make_pair(yy, xx));
							checked[yy][xx] = true;
						}
					}
				}

				if(surrounded) ans++;
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