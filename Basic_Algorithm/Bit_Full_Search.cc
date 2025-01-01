#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

#define rep(i, begin, limit) for(ll i = (ll)begin; i < (ll)limit; i++)

int main(){
	int N = 3;
	vector<int> row{1, 2, 3};

	rep(bit, 0, (1 << N)){
		cout << bit << ": " << '{';

		rep(i, 0, N){
			if(bit & (1 << i)){
				cout << row.at(i) << ' ';
			}
		}

		cout << '}' << endl;
	}

	return 0;
}