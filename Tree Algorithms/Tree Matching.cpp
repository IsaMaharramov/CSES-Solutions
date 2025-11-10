#include<bits/stdc++.h>
using namespace std;
constexpr int sz = 1e5 + 53243;
 
bool done[200005];
vector<int> g[200005];
int ans;
inline void Dfs(int node, int fa = 1){
	for(auto &to : g[node]){
		if(to == fa) continue;
		Dfs(to, node);
		if(!done[to] && !done[node]) done[to] = done[node] = 1, ++ans;
	}
	return;
}
 
signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for(register int i = 1, u, v; i < n; ++i){
		cin >> u >> v;
		g[u].emplace_back(v), g[v].emplace_back(u);
	}
	Dfs(1);
	cout << ans << '\n';
	return 0;
}