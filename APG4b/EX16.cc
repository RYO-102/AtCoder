//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> data(5);
  for (int i = 0; i < 5; i++) {
    cin >> data.at(i);
  }

  bool ans = false;
  // data�̒��ŗׂ荇���������v�f�����݂���Ȃ�"YES"���o�͂��A�����łȂ����"NO"���o�͂���
  // �����Ƀv���O������ǋL
  for(int i = 0; i < 4; i++){
	if(data.at(i) == data.at(i+1)){
		ans = true;
	}
  }

  if(ans == true){
	cout << "YES" << endl;
  }else{
	cout << "NO" << endl;
  }
}
