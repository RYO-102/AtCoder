//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
  int x, a, b;
  cin >> x >> a >> b;

  // 1.�̏o��
  x++;
  cout << x << endl;

  // ��������v���O������ǋL
  x *= (a + b);
  cout << x << endl;

  x *= x;
  cout << x << endl;

  x--;
  cout << x << endl;
  
}