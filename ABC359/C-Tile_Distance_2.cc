/*failed*/
#include <iostream>
#include <vector>
using namespace std;

int main(){
	long Sx, Sy, Tx, Ty;
	cin >> Sx >> Sy >> Tx >> Ty;

	//点を左から右にずらす
	if((Sx + Sy) % 2 != 0)Sx--;
	if((Tx + Ty) % 2 != 0)Tx--;

	//開始地点を原点にする
	Tx -= Sx;
	Ty -= Sy;

	//絶対値を取り、マイナスをなくす
	Tx = abs(Tx);
	Ty = abs(Ty);

	//cout << Tx << Ty << endl;
	//cout << Tx - Ty << endl;

	cout << (Ty + max(Tx, Ty)) / 2 << endl;
}