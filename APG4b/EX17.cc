//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, S;
  cin >> N >> S;
  vector<int> A(N), P(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  for (int i = 0; i < N; i++) {
    cin >> P.at(i);
  }

  // �����S�E�p�C�i�b�v�������ꂼ��1���w������Ƃ����vS�~�ɂȂ�悤�Ȕ����������ʂ肠�邩
  // �����Ƀv���O������ǋL
  int counter = 0;

  for(int i : A){
	for(int j : P){
		if((i + j) == S){
			counter++;
		}
	}
  }

  cout << counter << endl;
}
