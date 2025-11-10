#include<bits/stdc++.h>
using namespace std;
constexpr int sz = 1005, inf = 1E9;
int n, m, tot;
char grid[sz][sz];
struct cord{
	int x, y;
};
cord A;
int insecure[sz][sz], t[sz][sz];
 
array<int, 4> dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};
 
queue<cord> q;
 
cord p[sz][sz];
 
cord zro = {-1, -1};
 
signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(register int i = 1; i <= n; ++i){
		for(register int j = 1; j <= m; ++j){
			cin >> grid[i][j];
			insecure[i][j] = t[i][j] = inf;
			p[i][j] = {-1, -1};
			if(grid[i][j] == 'M'){
				q.push({i, j});
				insecure[i][j] = 0;
			}else if(grid[i][j] == 'A'){
				A = {i, j};
				t[i][j] = 0;
			}
		}
	}
	for(register int i = 0; i <= n + 1; ++i) grid[i][0] = grid[i][m+1] = '#';
	for(register int i = 0; i <= m + 1; ++i) grid[0][i] = grid[n+1][i] = '#';
	int x, y, tox, toy;
	while(!q.empty()){
		x = q.front().x, y = q.front().y;
		q.pop();
		
		
		for(register int i = 0; i < 4; ++i){
			tox = x + dx[i], toy = y + dy[i];
			if(grid[tox][toy] == '#' || insecure[tox][toy] != inf) continue;
			insecure[tox][toy] = insecure[x][y] + 1;
			q.push({tox, toy});
		}
		
		
		
	}
	
	
	q.push(A);
	
	while(!q.empty()){
		x = q.front().x, y = q.front().y;
		q.pop();
		
		for(register int i = 0; i < 4; ++i){
			tox = x + dx[i], toy = y + dy[i];
			if(grid[tox][toy] == '#' || t[tox][toy] != inf || t[x][y] + 1 >= insecure[tox][toy]) continue;
			t[tox][toy] = t[x][y] + 1;
			p[tox][toy] = {x, y};
			q.push({tox, toy});
		}
		
		
	}
	
	/*
	for(register int i = 1; i <= n; ++i){
		for(register int j = 1; j <= m; ++j){
			cout<<t[i][j] << ' ';
		}
		cout<<endl;
	}
*/	
	
	
//	cout<<t[4][8];
//	return 0;
 
	
	x = -1, y = -1;
	
	for(register int i = 1; i <= n; ++i){
		if(t[i][1] != inf){
			x = i, y = 1;
			break;
		}else if(t[i][m] != inf){
			x = i, y = m;
			break;
		}
	}
	
	for(register int i = 1; i <= m; ++i){
		if(t[1][i] != inf){
			x = 1, y = i;
			break;
		}else if(t[n][i] != inf){
			x = n, y = i;
			break;
		}
	}
	if(x == -1) return cout << "NO" << '\n', 0;
	
	cout << "YES" << '\n';
	
	
	
	cout << t[x][y] << '\n';
	
	string path = "";
	
	while(p[x][y].x != -1 && p[x][y].y != -1){
		
		
		if(p[x][y].x == x && p[x][y].y == y - 1){
			path += 'R';
		}else if(p[x][y].x == x && p[x][y].y == y + 1){
			path += 'L';
		}else if(p[x][y].x == x + 1 && p[x][y].y == y){
			path += 'U';
		}else if(p[x][y].x == x - 1 && p[x][y].y == y){
			path += 'D';
		}
		cord d = p[x][y];
		x = d.x, y = d.y;
	}
	reverse(path.begin(), path.end());
	
	cout << path << '\n';
	
	
	
	
	
	return 0;
}