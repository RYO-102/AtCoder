/*
ägí£EuclidÇÃå›èúñ@Ç…Ç®ÇØÇÈãtå≥åvéZ
https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a#3-5-%E6%8B%A1%E5%BC%B5-euclid-%E3%81%AE%E4%BA%92%E9%99%A4%E6%B3%95%E3%81%AB%E3%82%88%E3%82%8B%E9%80%86%E5%85%83%E8%A8%88%E7%AE%97:~:text=3%2D5.%20%E6%8B%A1%E5%BC%B5%20Euclid%20%E3%81%AE%E4%BA%92%E9%99%A4%E6%B3%95%E3%81%AB%E3%82%88%E3%82%8B%E9%80%86%E5%85%83%E8%A8%88%E7%AE%97
*/

#include <iostream>

using namespace std;
using ll = long long;

#define rep(i, begin, limit) for(ll i = (ll)begin; i < (ll)limit; i++)

//Ç±Ç±Ç©ÇÁ***************************************
ll modinv(ll a, ll m) {
	ll b = m, u = 1, v = 0;
	while(b){
		ll t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}
//Ç±Ç±Ç‹Ç≈ÉeÉìÉvÉåÅ[Ég*****************************

int main(){
	// mod.13 Ç≈ÇÃãtå≥ÇãÅÇﬂÇƒÇ›ÇÈ
	rep(i, 1, 13){
		cout << i << " 's inv: " << modinv(i, 13) << endl;
	}
}