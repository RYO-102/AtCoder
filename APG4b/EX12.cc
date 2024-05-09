//#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string S;
  cin >> S;

  // ここにプログラムを追記
  int count = 0;
  int sum = 1;

  for(int i = 0; i < S.size(); i++){
	if(S.at(i) == '1'){
		count++;
	}
  }

  if(count == 1){
	cout << sum << endl;
  }else{
	for(int i = 1; i < S.size() - 1; i++){
		if(S.at(i) == '+'){
			sum++;
		}else if(S.at(i) == '-'){
			sum--;
		}
	}
	cout << sum << endl;
  }
}
