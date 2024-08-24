#include <iostream>
#include <vector>
using namespace std;

int main(){
	//ABC 359 B
	int N, count = 0;
	cin >> N;
	vector<int> A(2 * N);
	for(int i = 0; i < 2 * N; i++){
		cin >> A.at(i);
	}

	for(int i = 0; i < (2 * N) - 2; i++){
		if(A.at(i) == A.at(i + 2)){
			count++;
		}
	}

	cout << count << endl;
}