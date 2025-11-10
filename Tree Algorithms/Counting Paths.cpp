#include<bits/stdc++.h>
 
using namespace std;
 
constexpr int sz = 2e5 + 5;
 
int n, m, tin[sz], tout[sz], fa[20][sz], c[sz], ans[sz];
 
vector<int> g[sz];
 
int timel;
 
inline void dfs(int node, int fath = 1){
	tin[node] = ++timel;
	fa[0][node] = fath;
	for(register int i = 1; i < 20; ++i){
		fa[i][node] = fa[i-1][fa[i-1][node]];
	}
	for(auto &to : g[node]){
		if(to == fath) continue;
		dfs(to, node);	
	}
	tout[node] = ++timel;
	return;
}
 
bool isAncestor(int u, int v){
	return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}
 
int LCA(int u, int v){
	if(isAncestor(u, v)) return u;
	if(isAncestor(v, u)) return v;
	for(register int i = 19; i >= 0; --i){
		if(!isAncestor(fa[i][u], v)) u = fa[i][u];
	}
	return fa[0][u];
}
 
int u, v;
 
signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(register int i = 1, u, v; i < n; ++i){
		cin >> u >> v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	dfs(1);
	for(register int i = 1; i <= m; ++i){
		cin >> u >> v;
		int lca = LCA(u, v);
		++c[u], ++c[v], --c[lca];
		if(lca ^ 1) --c[fa[0][lca]];
	}
	function<void(int, int)> Dfs = [&](int node, int fa){
		ans[node] += c[node];
		for(auto &to : g[node]){
			if(to == fa) continue;
			Dfs(to, node);
			ans[node] += ans[to];
		}
		return;
	};
	Dfs(1, 1);
	for(register int i = 1; i <= n; ++i){
		cout << ans[i] << " \n"[i == n];
	}
	return 0;
}