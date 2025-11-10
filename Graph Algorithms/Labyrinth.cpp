#include<bits/stdc++.h>
#define SPEED ios_base::sync_with_stdio();cin.tie(0);cout.tie(0)
#define ll long long
#define pii pair<int, int>
#define f first
#define s second
#define mpr make_pair
#define y yyyyy
#define eb emplace_back
#define all(v) v.begin(), v.end()
 
using namespace std;
 
int n, m;
queue<pii> q;
char grid[1003][1003];
int fa[1003][1003];
bool vis[1003][1003];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
string dir = "URDLN";
 
bool OK(int &x, int &y){
	return (x >= 0 && y >= 0 && x < n && y < m);
}
 
 
int main(){
	SPEED;
	cin >> n >> m;
	int fx, fy;
	for(register int i = 0; i < n; ++i){
		for(register int j = 0; j < m; ++j){
			cin >> grid[i][j];
			if(grid[i][j] == 'A') q.push({i, j}), fa[i][j] = 4, vis[i][j] = true;
			if(grid[i][j] == 'B') fx = i, fy = j;
		}
	}
	int tox, toy;
	vector<int> v;
	while(!q.empty()){
		int x = q.front().f, y = q.front().s;
		q.pop();
		for(register int i = 0; i < 4; ++i){
			tox = x + dx[i], toy = y + dy[i];
			if(!OK(tox, toy)) continue;
			if(vis[tox][toy]) continue;
			if(grid[tox][toy] == '#') continue;
			vis[tox][toy] = true;
			fa[tox][toy] = i;
			q.push({tox, toy});
		}
	}
	if(!vis[fx][fy]) return puts("NO"), 0;
	cout << "YES" << '\n';
	int x = fx, y = fy;
	while(fa[x][y] ^ 4){
		v.eb(fa[x][y]);
		int d = fa[x][y];
		x -= dx[d], y -= dy[d];
	}
	cout << (int)v.size() << '\n';
	reverse(all(v));
	for(auto to : v) cout << dir[to];
	cout << '\n';
	return 0;
}