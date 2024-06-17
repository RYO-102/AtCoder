//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;

  int shortest = min(min(A, B), C);
  int longest = max(max(A, B), C);

  cout << longest - shortest << endl;
}