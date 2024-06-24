//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>
using namespace std;

int main(){
	using pii = pair<int, int>;
	int N;
	vector<pii> vec;
	
	cin >> N;

	for(int i = 0; i < N; i++){
		int a, b;
		cin >> a >> b;

		vec.push_back(make_pair(b, a));
	}

	sort(vec.begin(), vec.end());

	for(auto t : vec){
		int a, b;
		tie(b, a) = t;
		cout << a << ' ' << b << endl;
	}
}