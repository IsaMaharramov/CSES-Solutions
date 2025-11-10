#include<bits/stdc++.h>
 
#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif
 
using namespace std;
 
string s;
 
bool vis[9][9];
 
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
 
int tox, toy;
 
int Dfs(int x, int y, int j){
	int res(0);
	if(x == 7 && y == 1) return j == 48;
	if(vis[x-1][y] && vis[x+1][y] && !vis[x][y-1] && !vis[x][y+1]) return 0;   	/// WALL : 
	if(vis[x][y-1] && vis[x][y+1] && !vis[x-1][y] && !vis[x+1][y]) return 0;
	vis[x][y] = true;
	if(s[j] == '?'){
		for(register int i = 0; i < 4; ++i){
			tox = x + dx[i], toy = y + dy[i];
			if(vis[tox][toy]) continue;
			res += Dfs(tox, toy, j + 1);
		}
	}else{
		tox = x, toy = y;
		if(s[j] == 'L') --toy;
		if(s[j] == 'R') ++toy;
		if(s[j] == 'D') ++tox;
		if(s[j] == 'U') --tox;
		if(!vis[tox][toy]){
			res += Dfs(tox, toy, j + 1);
		}
	}
	vis[x][y] = false;
	return res;
}
 
signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> s;
	for(register int i = 1; i < 8; ++i) vis[i][8] = vis[8][i] = vis[0][i] = vis[i][0] = true;
	int ans = Dfs(1, 1, 0);
	cout << ans << '\n';
	return 0;
}