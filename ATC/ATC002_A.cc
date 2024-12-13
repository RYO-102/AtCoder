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
#include <queue>
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

int R, C, sy, sx, gy, gx;
vector<vector<char>> c;

int main(){
	//ATC 002 A
	cin >> R >> C >> sy >> sx >> gy >> gx;
	c.resize(R, vector<char>(C));
	rep(i, 0, R){
		rep(j, 0, C) cin >> c.at(i).at(j);
	}

	vector<vector<int>> dist(R, vector<int>(C, -1));
	queue<vector<int>> que;

	R -= 1; C -= 1; sy -= 1; sx -= 1; gy -= 1; gx -= 1;

	dist.at(sy).at(sx) = 0;
	que.push({sy, sx});

	while(!que.empty()){
		vector<int> dy{-1, 0, 1, 0}, dx{0, 1, 0, -1};

		//vector<int> v = que.front();
		int vy = que.front().at(0), vx = que.front().at(1);
		que.pop();

		rep(i, 0, 4){
			int new_vy = vy + dy.at(i);
			int new_vx = vx + dx.at(i);

			if(new_vy < 0 || R < new_vy || new_vx < 0 || C < new_vy) continue;

			if(c.at(new_vy).at(new_vx) == '#' || dist.at(new_vy).at(new_vx) != -1) continue;

			dist.at(new_vy).at(new_vx) = dist.at(vy).at(vx) + 1;
			que.push({new_vy, new_vx});
		}
	}

	cout << dist.at(gy).at(gx) << endl;

	return 0;
}