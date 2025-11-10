#include "bits/stdc++.h"
using namespace std;
#define int long long
constexpr int sz = 2e5 + 5;
constexpr int mod = 1e9 + 7;
 
int n, q, v[sz], sizel[sz], fa[sz], d[sz], st[1 << 20], id[sz], tp[sz];
vector<int> g[sz];
 
void update(int node, int val){
    st[node += n] = val;
    for(node >>= 1; node; node >>= 1) st[node] = max(st[node << 1], st[node << 1 | 1]);
}
 
int query(int l, int r){
    int r1(0), r2(0);
    for(l += n, r += (n + 1); l < r; l >>= 1, r >>= 1){
        if(l & 1) r1 = max(r1, st[l++]);
        if(r & 1) r2 = max(r2, st[--r]);
    }
    return max(r1, r2);
}
 
int dfs_sz(int node = 1, int fath = 1){
    sizel[node] = 1;
    fa[node] = fath;
    for(int &to : g[node]){
        if(to == fath) continue;
        d[to] = d[node] + 1;
        fa[to] = node;
        sizel[node] += dfs_sz(to, node);
    }
    return sizel[node];
}
 
int ct = 1;
 
void dfs_hld(int node = 1, int fath = 1, int top = 1){ // Thanks -> Shahriar Rashid
    id[node] = ct++;
    tp[node] = top;
    update(id[node], v[node]);
    int h_to = -1, h_sz = -1;
    for(int &to : g[node]){
        if(to == fath) continue;
        if(sizel[to] > h_sz){
            h_sz = sizel[to];
            h_to = to;
        }
    }
    if(h_to == -1) return;
    dfs_hld(h_to, node, top);
    for(int &to : g[node]){
        if(to == fath or to == h_to) continue;
        dfs_hld(to, node, to);
    }
}
 
int path(int x, int y){
    int res = 0;
    while(tp[x] != tp[y]){
        if(d[tp[x]] < d[tp[y]]) swap(x, y);
        res = max(res, query(id[tp[x]], id[x]));
        x = fa[tp[x]];
    }
    if(d[x] > d[y]) swap(x, y);
    res = max(res, query(id[x], id[y]));
    return res;
}
 
 
void solve(){
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> v[i];
    for(int i = 1, u, v; i < n; ++i){
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs_sz();
    dfs_hld();
    int t, a, b;
    while(q--){
        cin >> t >> a >> b;
        if(t ^ 1){
            cout << path(a, b) << ' ';
        }else{
            v[a] = b;
            update(id[a], v[a]);
        }
    }
}
 
signed main(){
    ios_base::sync_with_stdio(false), cout.tie(0), cin.tie(0);
    int T{1};
    //cin >> T;
    while(T--) solve();
    return 0;
}