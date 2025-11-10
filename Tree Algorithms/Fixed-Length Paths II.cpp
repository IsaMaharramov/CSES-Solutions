#include "bits/stdc++.h"
using namespace std;
#define int long long
constexpr int sz = 2e5 + 5;
constexpr int mod = 1e9 + 7;
 
int n, k1, k2, ans, mul = 1, maxl;
vector<int> g[sz];
 
int get_prefix(const deque<int> &a, int mx){
    if(mx < 0) return 0;
    if(mx + 1 >= (int)a.size()) return a[0];
    return a[0] - a[mx + 1];
}
 
void fixit(deque<int> &a, deque<int> &b){
    if((int)a.size() < (int)b.size()) swap(a, b);
    for(int i = 0; i < (int)b.size() - 1; ++i){
        b[i] -= b[i + 1];
    }
    for(int i = 0; i < (int)b.size(); ++i){
        ans += b[i] * (get_prefix(a, k2 - i) - get_prefix(a, k1 - 1 - i));
    }
    for(int i = (int)b.size() - 2; i >= 0; --i){
        b[i] += b[i + 1];
    }
    for(int i = (int)b.size() - 1; i >= 0; --i) a[i] += b[i];
}
 
deque<int> dfs(int node, int fa){   /// Thanks -> Andi Qu, Benjamin Qi, Michael Chen
    deque<int> res{1};
    for(int &to : g[node]){
        if(to == fa) continue;
        deque<int> a = dfs(to, node);
        a.push_front(a.front());
        fixit(res, a);
    }
    return res;
}
 
void solve(){
    cin >> n >> k1 >> k2;
    for(int i = 1, u, v; i < n; ++i){
        cin >> u >> v;
        g[u].emplace_back(v), g[v].emplace_back(u);
    }
    maxl = k1 - 1, mul = -1;
    dfs(1, 0);
    cout << ans << '\n';
}
 
signed main(){
    ios_base::sync_with_stdio(false), cout.tie(0), cin.tie(0);
    int T{1};
    //cin >> T;
    while(T--) solve();
    return 0;
}