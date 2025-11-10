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
 
int tin[sz], tout[sz];
 
int fa[20][sz];
 
int timel(0);
 
bool isAncestor(int a, int b){
	return (tin[a] <= tin[b] && tout[a] >= tout[b]);
}
 
int d[sz];
 
 
inline void Dfs(int node, int par = 1){
	tin[node] = ++timel;
	fa[0][node] = par;
	for(register int i = 1; i < 20; ++i){
	    fa[i][node] = fa[i-1][fa[i-1][node]];
    }
	for(auto &to : g[node]){
		if(to == par) continue;
		d[to] = d[node] + 1;
		Dfs(to, node);
	}
	tout[node] = ++timel;
	return;
}
 
int LCA(int a, int b){
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
	for(register int i = 1, a, b; i < n; ++i){
		cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);		
	}
	Dfs(1);
	int a, b;
	while(q--){
		cin >> a >> b;
		cout << d[a] + d[b] - 2 * d[LCA(a, b)] << '\n';
	}
	return 0;
}