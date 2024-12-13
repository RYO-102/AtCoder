#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <bitset>
#include <set>
#include <regex>
#include <cstdint>
#include <stack>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using graph = vector<vector<int>>;

#define rep(i, begin, limit) for(ll i = (ll)begin; i < (ll)limit; i++)
#define irep(i, begin, limit) for(ll i = (ll)begin; i <= (ll)limit; i++)
#define rrep(i, begin, limit) for(ll i = (ll)begin; i > (ll)limit; i--)
#define rirep(i, begin, limit) for(ll i = (ll)begin; i >= (ll)limit; i--)
#define all(vec_name) vec_name.begin(), vec_name.end()
#define rall(vec_name) vec_name.rbegin(), vec_name.rend()

//sort(S.bigin(), S.end(), greater<int>())
//set<type> insert(n) erase(n) name.count(n)
//map<type,type> [key]=n erase(key)
//pair<type, type> .first .second
//vector<vector<int>> area(H, vector<int>(W, 0));
//順列 next_permutation(all(vector))

//sort O(NlogN)
//S.substr(開始位置, 取り出す長さ);
//int 最大値 2,147,483,647
//TLE目安 10^8がアウト

int H, W;
vector<vector<char>> c;
vector<vector<bool>> seen;

void DFS(int y, int x){
	vector<int> dy{0, 1, 0, -1}, dx{1, 0, -1, 0};
	seen.at(y).at(x) = true;

	rep(i, 0, 4){
		int new_y = y + dy.at(i);
		int new_x = x + dx.at(i);

		if(new_y < 0 || H <= new_y || new_x < 0 || W <= new_x) continue;

		if(c.at(new_y).at(new_x) == '#' || seen.at(new_y).at(new_x)) continue;
		else DFS(new_y, new_x);
	}

	return;
}

int main(){
	//ATC 001 A
	cin >> H >> W;
	c.resize(H);
	rep(i, 0, H){
		rep(j, 0, W){
		 	char tmp;
		 	cin >> tmp;
		 	c.at(i).push_back(tmp);
		}
	}

	int s_x = -1, s_y = -1, g_x = -1, g_y = -1;
	rep(i, 0, H){
		rep(j, 0, W){
			if(c.at(i).at(j) == 's'){
				s_y = i;
				s_x = j;
			}else if(c.at(i).at(j) == 'g'){
				g_y = i;
				g_x = j;
			}
		}
	}

	seen.assign(H, vector<bool>(W, false));

	DFS(s_y, s_x);

	if(seen.at(g_y).at(g_x)) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}