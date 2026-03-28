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

void solve() {
	//ABC451_C
	ll Q;
	cin >> Q;
	
	priority_queue<ll, vector<ll>, greater<ll>> pq;

	while(Q--){
		ll query, h;
		cin >> query >> h;

		if(query == 1){
			pq.push(h);
		}else{
			while(!pq.empty() && pq.top() <= h){
				pq.pop();
			}
		}

		cout << pq.size() << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}