/*
Binary_Search
https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B&lang=ja
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
using vll = vector<ll>;

#define rep(i, begin, limit) for(ll i = (ll)begin; i < (ll)limit; i++)

//Declaration
ll n, q;
vll S, T;

int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

	// ���́F�z��S�A�����Ώ�T
	cin >> n;
	S.resize(n);
	rep(i, 0, n) cin >> S.at(i);
	cin >> q;
	T.resize(q);
	rep(i, 0, q) cin >> T.at(i);

	ll ans = 0;

	// T�̊e�v�f�ɑ΂��ē񕪒T��
	rep(i, 0, q){
		// [ng, ok)��������(ok, ng]
		ll ok = n, ng = -1;

		// ���J��Ԃ̓񕪒T��
		while(abs(ok - ng) > 1){
			ll mid = (ok + ng) / 2;

			if(T.at(i) <= S.at(mid)){
				ok = mid;
			}else{
				ng = mid;
			}
		}

		// �l����v����΃J�E���g
		if(ok != n && S.at(ok) == T.at(i)) ans++;
	}
	
	// �o�����������o��
	cout << ans << endl;

	return 0;
}