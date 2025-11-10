#include<bits/stdc++.h>
using namespace std;
constexpr int sz = 2e5 + 5;
 
vector<int> g[sz];
 
int n, q, a[sz], tin[sz], tout[sz], timel;
 
unordered_map<int, int> Tin;
 
inline void Dfs(int node, int fa){
	tin[node] = ++timel;
	Tin[tin[node]] = node;
	for(auto &to : g[node]){
		if(to == fa) continue;
		Dfs(to, node);
	}
	tout[node] = ++timel;
	return;
}
 
long long tree[sz << 4];
 
inline void push_up(int node){
	tree[node] = tree[node << 1] + tree[node << 1 | 1];
	return;
}
 
inline void build(int l, int r, int node){
	if(l == r){
		tree[node] = a[Tin[l]];
		return;
	}
	int mid = l + ((r - l) >> 1);
	build(l, mid, node << 1);
	build(mid + 1, r, node << 1 | 1);
	push_up(node);
	return;
}
 
inline void update(int l, int r, int node, int x, int val){
	if(l > x || x > r || r < l) return;
	if(l == r){
		tree[node] = val;
		return;
	}
	int mid = l + ((r - l) >> 1);
	update(l, mid, node << 1, x, val);
	update(mid + 1, r, node << 1 | 1, x, val);
	push_up(node);
	return;
}
 
long long get_ans(int l, int r, int node, int L, int R){
	if(l > R || r < L || r < l) return 0ll;
	if(l >= L && r <= R) return tree[node];
	int mid = l + ((r - l) >> 1);
	return get_ans(l, mid, node << 1, L, R) + get_ans(mid + 1, r, node << 1 | 1, L, R);
}
 
signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for(register int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	for(register int i = 1, u, v; i < n; ++i){
		cin >> u >> v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	Dfs(1, 1);
	build(1, n << 1 + 1, 1);
	int type, l, r;
	while(q--){
		cin >> type >> l;
		if(type == 1){
			cin >> r;
			update(1, n << 1 + 1, 1, tin[l], r);
		}else{
			cout << get_ans(1, n << 1 + 1, 1, tin[l], tout[l]) << '\n';
		}
	}
	return 0;
}