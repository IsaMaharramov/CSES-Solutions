#include<bits/stdc++.h>
using namespace std;
constexpr int sz = 2e5 + 5;
 
int n, Q, a[sz];
 
struct Node{
	long long pref, sum;
} tree[sz << 2];
 
 
Node operator+(Node A, Node B){
	return {max({A.sum + B.pref, A.sum + B.sum, A.pref, 0ll}), A.sum + B.sum};
}
 
inline void push_up(int node){
	tree[node] = tree[node << 1] + tree[node << 1 | 1];
	return;
}
 
inline void build(int l, int r, int node){
	if(l == r){
		tree[node] = {max(0, a[l]), a[l]};
		return;
	}
	int mid = l + ((r - l) >> 1);
	build(l, mid, node << 1);
	build(mid + 1, r, node << 1 | 1);
	push_up(node);
	return;	
}
 
inline void update(int l, int r, int node, int x, int val){
	if(l > x || r < x || r < l) return;
	if(l == r){
		tree[node] = {max(0, val), val};
		return;
	}
	int mid = l + ((r - l) >> 1);
	update(l, mid, node << 1, x, val);
	update(mid + 1, r, node << 1 | 1, x, val);
	push_up(node);
	return;
}
 
Node Zro;
 
Node get_ans(int l, int r, int node, int L, int R){
	if(l > R || r < L || r < l) return Zro;
	if(l >= L && r <= R) return tree[node];
	int mid = l + ((r - l) >> 1);
	return get_ans(l, mid, node << 1, L, R) + get_ans(mid + 1, r, node << 1 | 1, L, R);
}
 
signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> Q;
	for(register int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	build(1, n, 1);
	int type, l, r;
	while(Q--){
		cin >> type >> l >> r;
		if(type == 1){
			update(1, n, 1, l, r);
		}else{
			cout << get_ans(1, n, 1, l, r).pref << '\n';
		}
	}
	return 0;
}