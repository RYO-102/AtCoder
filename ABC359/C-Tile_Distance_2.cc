/*failed*/
#include <iostream>
#include <vector>
using namespace std;

int main(){
	long Sx, Sy, Tx, Ty;
	cin >> Sx >> Sy >> Tx >> Ty;

	//�_��������E�ɂ��炷
	if((Sx + Sy) % 2 != 0)Sx--;
	if((Tx + Ty) % 2 != 0)Tx--;

	//�J�n�n�_�����_�ɂ���
	Tx -= Sx;
	Ty -= Sy;

	//��Βl�����A�}�C�i�X���Ȃ���
	Tx = abs(Tx);
	Ty = abs(Ty);

	//cout << Tx << Ty << endl;
	//cout << Tx - Ty << endl;

	cout << (Ty + max(Tx, Ty)) / 2 << endl;
}