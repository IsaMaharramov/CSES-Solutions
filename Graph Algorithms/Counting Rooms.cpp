#include<iostream>
#include<vector>
#include<random>
#include<chrono>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_set>
#define SPEED ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define oo 1000000001
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define ll long long
#define ull unsigned long long
 
using namespace std;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int sz = 1003;
 
int n, m;
char ch;
bool vis[sz][sz];
 
int dx[ ] = {1, -1, 0, 0};
int dy[ ] = {0, 0, -1, 1};
 
bool OK(int x, int y){
    return (x >= 1 && y >= 1 && x <= n && y <= m);
}
 
inline void dfs(int x, int y){
    vis[x][y] = true;
    for(register int i = 0; i < 4; ++i){
        int tox = x + dx[i], toy = y + dy[i];
        if(!OK(tox, toy)) continue;
        if(vis[tox][toy]) continue;
        dfs(tox, toy);
    }
    return;
}
 
signed main(){
	SPEED;
	cin >> n >> m;
	for(register int i = 1; i <= n; ++i){
        for(register int j = 1; j <= m; ++j){
            cin >> ch;
            vis[i][j] = (ch == '#');
        }
	}
	int rooms(0);
	for(register int i = 1; i <= n; ++i){
        for(register int j = 1; j <= m; ++j){
            if(!vis[i][j]){
                ++rooms;
                dfs(i, j);
            }
        }
	}
	cout << rooms << '\n';
	return 0;
}