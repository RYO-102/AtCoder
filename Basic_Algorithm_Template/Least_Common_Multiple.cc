/*
Greatest_Common_Divisor
https://qiita.com/e869120/items/518297c6816adb67f9a5#3-6-%E6%9C%80%E5%A4%A7%E5%85%AC%E7%B4%84%E6%95%B0-__gcd
*/

#include <iostream>

using namespace std;
using ll = long long;

//Declaration
ll x, y;

// ユークリッドの互除法による最大公約数 (GCD)
ll gcd(ll a, ll b){
	if(b == 0) return a;
	else return gcd(b, a % b);
}

// GCD を利用して最小公倍数 (LCM) を計算
ll lcm(ll a, ll b){
	return a / gcd(a, b) * b;
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

	cin >> x >> y;
	
	cout << lcm(x, y) << endl;

	return 0;
}