#include "bits/stdc++.h"
using namespace std;
#define int long long
constexpr int sz = 2e5 + 5;
constexpr int mod = 1e9 + 7;
constexpr int inf = 1e18 + 7;
 
int n, q, fa[20][sz], d[sz];
bitset<sz> vis;
 
void solve(){
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        cin >> fa[0][i];
    }
    for(int j = 1; j < 20; ++j){
        for(int i = 1; i <= n; ++i){
            fa[j][i] = fa[j - 1][fa[j - 1][i]]; // 
        }
    }
    function<void(int)> Dfs = [&](int node){
        if(vis[node]) return;
        vis[node] = 1;
        Dfs(fa[0][node]);
        d[node] = d[fa[0][node]] + 1;
        return;
    };
 
    auto up = [&](int x, int y){
        if(y <= 0) return x;
        for(int j = 19; j >= 0; --j){
            if((1 << j) & y) x = fa[j][x];
        }
        return x;
    };
 
    for(int node = 1; node <= n; ++node){
        if(!vis[node]){
            Dfs(node);
        }
    }
 
    register int x, y;
 
    while(q--){
        cin >> x >> y;
        int xp = up(x, d[x]);
        if(up(x, d[x] - d[y]) == y){
            cout << d[x] - d[y] << '\n';
        }else if(up(xp, d[xp] - d[y]) == y){
            cout << d[x] + d[xp] - d[y] << '\n';
        }else{
            cout << -1 << '\n';
        }
    }
    return;
}
 
signed main(){
    ios_base::sync_with_stdio(false), cout.tie(0), cin.tie(0);
    int T{1};
    //cin >> T;
    while(T--) solve();
    return 0;
}