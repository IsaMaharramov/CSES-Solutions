#include "bits/stdc++.h"
using namespace std;
 
constexpr int sz = 1e5 + 5;
 
int n, m;
bool f;
vector<int> g[2][sz];
bitset<sz> vis;
 
inline void Dfs(int node){
	vis[node] = true;
	for(auto &to : g[f][node]){
		if(vis[to]) continue;
		Dfs(to);
	}
	return void();
}
 
signed main(){
	ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
	cin >> n >> m;
	for(register int i = 1, u, v; i <= m; ++i){
		cin >> u >> v;
		g[0][u].emplace_back(v);
		g[1][v].emplace_back(u);
	}
	Dfs(1);
	for(register int i = 1; i <= n; ++i){
		if(!vis[i]){
			return cout << "NO\n" << 1 << ' ' << i << '\n', 0; 
		}
	}
	f ^= 1;
	vis.reset();
	Dfs(1);
	for(register int i = 1; i <= n; ++i){
		if(!vis[i]){
			return cout << "NO\n" << i << ' ' << 1 << '\n', 0;
		}
	}
	return cout << "YES" << '\n', 0;
}