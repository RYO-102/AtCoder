#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;
using ll = long long;

#define rep(i, begin, limit) for(ll i = (ll)begin; i < (ll)limit; i++)
#define rrep(i, begin, limit) for(ll i = (ll)begin; i > (ll)limit; i--)

const ll INF = 1LL << 60;

void solve() {
	//ABC447_B
	string S;
	cin >> S;

	vector<ll> bucket(26, 0);
	rep(i, 0, S.size()) bucket[S[i] - 'a']++;

	set<char> remove;

	rep(i, 0, 26){
		if(bucket[i] == *max_element(bucket.begin(), bucket.end())){
			remove.insert((char)(i + 'a'));
		}
	}

	rep(i, 0, S.size()){
		if(remove.count(S[i])) continue;
		else cout << S[i];
	}

	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}