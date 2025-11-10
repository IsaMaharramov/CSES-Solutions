#include<bits/stdc++.h>
using namespace std;
 
constexpr int sz = 2e5 + 5;
 
int n, m, sizel[sz], fa[sz], components;
 
int find_set(int v){
	if(fa[v] == v)
		return v;
	return fa[v] = find_set(fa[v]);
}
 
bool Union(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if(a ^ b){
		if(sizel[a] > sizel[b]) swap(a, b);
		sizel[b] += sizel[a];
		fa[a] = fa[b];
		components--;
		return true;
	}
	return false;
}
 
inline void init(){
	components = n;
	for(register int i = 1; i <= n; ++i) sizel[i] = 1, fa[i] = i;
	return;
}
 
struct Node{
	int u, v, w;
};
 
vector<Node> len;
 
signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	init();
	len.resize(m);
	for(register int i = 0; i < m; ++i){
		cin >> len[i].u >> len[i].v >> len[i].w;
	}
	function<bool(Node, Node)> cmp = [](Node a, Node b){
		return a.w < b.w;
	};
	sort(len.begin(), len.end(), cmp);
	long long ans(0);
	for(register int i = 0; i < m; ++i){
		if(Union(len[i].u, len[i].v)) ans += len[i].w;
	}
	if(components ^ 1) return puts("IMPOSSIBLE"), 0;
	cout << ans << '\n';
	return 0;
}