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
	//ABC447_C
	string S, T;
	cin >> S >> T;

	string S_removeA = "", T_removeA = "";
	rep(i, 0, S.size()){
		if(S[i] != 'A') S_removeA += S[i];
	}
	rep(i, 0, T.size()){
		if(T[i] != 'A') T_removeA += T[i];
	}

	if(S_removeA != T_removeA){
		cout << "-1\n";
		return;
	}
	
	ll method_num = 0;
	ll S_index = 0, T_index = 0;

	while(S_index < S.size() || T_index < T.size()){
		if(S_index == S.size()){
			method_num++;
			T_index++;
		}else if(T_index == T.size()){
			method_num++;
			S_index++;
		}else if(S[S_index] == T[T_index]){
			S_index++;
			T_index++;
		}else if(S[S_index] == 'A'){
			method_num++;
			S_index++;
		}else{
			method_num++;
			T_index++;
		}
	}

	cout << method_num << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}