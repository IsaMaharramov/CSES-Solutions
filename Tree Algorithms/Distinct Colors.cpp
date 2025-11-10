#include<bits/stdc++.h>
using namespace std;
constexpr int sz = 2e5 + 5;
 
int n, c[sz];
vector<int> g[sz];
 
set<int> st[sz];
 
int ans[sz];
 
inline void Dfs(int node, int fa){
	st[node].insert(c[node]);
	for(auto &to : g[node]){
		if(to == fa) continue;
		Dfs(to, node);
		if((int)st[node].size() < (int)st[to].size()){
			swap(st[node], st[to]);
		}
		for(auto &color : st[to]) st[node].insert(color);
	}
	ans[node] = (int)st[node].size();
	return;
}
 
signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for(register int i = 1; i <= n; ++i){
		cin >> c[i];
	}
	for(register int i = 1, u, v; i < n; ++i){
		cin >> u >> v;
		g[u].emplace_back(v); g[v].emplace_back(u);
	}
	Dfs(1, 1);
	for(register int i = 1; i <= n; ++i){
		cout << ans[i] << ' ';
	}
	return 0;
}