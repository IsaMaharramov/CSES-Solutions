#include<bits/stdc++.h>
using namespace std;
constexpr int sz = 2e5 + 5;
 
int n, centroid{-1};
vector<int> g[sz];
int Dfs(int node, int fa = 1){
	if(centroid != -1) return 0;
	int subtree_size = 1;
	for(auto &to : g[node]){
		if(to == fa) continue;
		subtree_size += Dfs(to, node); 
	}
	if(subtree_size > n / 2 && centroid == -1) centroid = node;
	return subtree_size;
}
 
signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for(register int i = 1, u, v; i < n; ++i){
		cin >> u >> v;
		g[u].emplace_back(v); g[v].emplace_back(u);
	}
	Dfs(1);
	cout << centroid << '\n';
	return 0;
}