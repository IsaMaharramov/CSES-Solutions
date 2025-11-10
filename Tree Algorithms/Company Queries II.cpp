#include<bits/stdc++.h>
 
#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif
 
using namespace std;
 
constexpr int sz = 2e5 + 5;
 
int n, q;
 
vector<int> g[sz];
 
int fa[20][sz];
 
int tin[sz], tout[sz];
 
int timel(0);
 
inline void Dfs(int node, int pa){
	tin[node] = ++timel;
	for(register int i = 1; i < 20; ++i){
		fa[i][node] = fa[i-1][fa[i-1][node]];
	}
	for(auto to : g[node]){
		if(to == pa) continue;
		Dfs(to, node);
		
	}
	tout[node] = ++timel;
	return;
}
 
bool isAncestor(int &a, int &b){
	return (tin[a] <= tin[b] && tout[a] >= tout[b]);
}
 
int LCA(int &a, int &b){
	if(isAncestor(a, b)) return a;
	if(isAncestor(b, a)) return b;
	for(register int i = 19; i >= 0; --i){
		if(!isAncestor(fa[i][a], b)) a = fa[i][a];
	}
	return fa[0][a];
}
 
signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> q;
	fa[0][1] = 1;
	for(register int i = 2, e; i <= n; ++i){
		cin >> e;
		debug(e);
		fa[0][i] = e;
		g[e].emplace_back(i), g[i].emplace_back(e);	
	}
	Dfs(1, 1);
	int a, b;
	while(q--){
		cin >> a >> b;
		cout << LCA(a, b) << '\n';
	}
	return 0;
}
