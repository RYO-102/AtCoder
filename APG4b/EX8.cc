//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
  int p;
  cin >> p;

  int price, N;
  string text;

  // �p�^�[��1
  if (p == 1) {
    cin >> price >> N;
  }

  // �p�^�[��2
  if (p == 2) {
    cin >> text >> price >> N;
    cout << text << "!" << endl;
  }

  cout << price * N << endl;
}