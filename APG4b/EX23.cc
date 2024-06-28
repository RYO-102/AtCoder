//times:63ms
//#define _GLIBCXX_DEBUG
//forループにおいて#define _GLIBCXX_DEBIGを追加するとフリーズすることがわかった。
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
	map<int, int> number;
	int a, N, max_num, max_appear = 0;
	cin >> N;

	for(int i = 0; i < N; i++){
		cin >> a;
		if(number.count(a)){
			number.at(a)++;
		}else{
			number[a] = 1;
		}
	}

	/*for(auto x : number){
		auto p = x.first;
		auto q = x.second;
		cout << p << "=>" << q << endl;
	}*/

	for(auto x: number){
		if(max_appear < x.second){
			max_num = x.first;
			max_appear = x.second;
		}
	}

	cout << max_num << ' ' << max_appear << endl;
}