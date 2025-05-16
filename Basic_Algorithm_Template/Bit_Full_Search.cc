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

	// ���́F�v�f��N�A�ڕW�lX�A����A
	cin >> N >> X;
	A.resize(N);
	rep(i, 0, N) cin >> A.at(i);

	bool ans = false;

	// 2^N�ʂ�̕����W����S�T��
	rep(bit, 0, (1 << N)){
		ll sum = 0;

		// �e�r�b�g�ɑΉ�����v�f��I�Ԃ��ǂ���
		rep(i, 0, N){
			if(bit & (1 << i)) sum += A.at(i);
		}

		// �����W���̘a��X�Ɉ�v���邩
		if(sum == X) ans = true;
	}

	// ���ʂ̏o��
	if(ans) Yes;
	else No;

	return 0;
}