#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;
using ll = long long;

#define rep(i, begin, limit) for(ll i = (ll)begin; i < (ll)limit; i++)
#define rrep(i, begin, limit) for(ll i = (ll)begin; i > (ll)limit; i--)

void solve() {
	ll N;
	if(!(cin >> N)) return;
	vector<ll> A(N);
	for(auto& i : A) if(!(cin >> i)) return;

	vector<ll> A_sort = A;
	sort(A_sort.begin(), A_sort.end());
	
	ll a = 1;
	map<ll, ll> rank;
	rep(i, 0, N){
		if(rank.find(A_sort[i]) == rank.end()) rank[A_sort[i]] = a++;
	}

	rep(i, 0, N) cout << rank[A[i]] << ' ';
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}