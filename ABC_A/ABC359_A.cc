#include <iostream>
using namespace std;

int main() {
  //ABC 359 A
  int N, count = 0;
  string S;
  cin >> N;

  for(int i = 0; i < N; i++){
	cin >> S;
	if(S == "Takahashi"){
		count++;
	}
  }

  cout << count << endl;
}
