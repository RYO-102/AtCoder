/*
Bit_Full_Search
https://qiita.com/e869120/items/25cb52ba47be0fd418d6#3-1-bit-%E5%85%A8%E6%8E%A2%E7%B4%A2
*/

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using vll = vector<ll>;

#define rep(i, begin, limit) for(ll i = (ll)begin; i < (ll)limit; i++)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl

//Declaration
ll N, X;
vll A;

int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

	// 入力：要素数N、目標値X、数列A
	cin >> N >> X;
	A.resize(N);
	rep(i, 0, N) cin >> A.at(i);

	bool ans = false;

	// 2^N通りの部分集合を全探索
	rep(bit, 0, (1 << N)){
		ll sum = 0;

		// 各ビットに対応する要素を選ぶかどうか
		rep(i, 0, N){
			if(bit & (1 << i)) sum += A.at(i);
		}

		// 部分集合の和がXに一致するか
		if(sum == X) ans = true;
	}

	// 結果の出力
	if(ans) Yes;
	else No;

	return 0;
}