#include <iostream>
#include <vector>
using namespace std;

int main(){
	int N;
	cin >> N;

	vector<int> vec1(N);
	int sum = 0, ave;

	for(int i = 0; i < N; i++){
		cin >> vec1.at(i);
		sum += vec1.at(i);
	}
	ave = sum / N;

	for(int i = 0; i < N; i++){
		if(ave > vec1.at(i)){
			cout << ave - vec1.at(i) << endl;
		}else{
			cout << vec1.at(i) - ave << endl;
		}
	}
}