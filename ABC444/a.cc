#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

void solve() {
	string N;
	cin >> N;

	if(N[0] == N[1] && N[1] == N[2]) cout << "Yes" << endl;
	else cout << "No" << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}