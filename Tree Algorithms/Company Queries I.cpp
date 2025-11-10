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
 
 
void dfs(int node, int pa){
	for(register int i = 1; i < 20; ++i){
		fa[i][node] = fa[i-1][fa[i-1][node]];       /// 2^(i-1) + 2^(i-1) = 2 * 2^(i-1) = 2 ^ i
	}
	for(auto to : g[node]){
		if(to == pa) continue;
		dfs(to, node);
	}
	return;
}
 
 
signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for(register int i = 2, e; i <= n; ++i){
		cin >> e;
		fa[0][i] = e;
		g[e].emplace_back(i);
	}
	dfs(1, 1);
	int x, k;
	while(q--){
		cin >> x >> k;
		for(register int i = 0; i < 20; ++i){
			if((1 << i) & k){
				x = fa[i][x];
			}
		}
		cout << (x ? x : -1) << '\n';
	}
	return 0;
}