#include "bits/stdc++.h"
using namespace std;
 
#define int long long
 
int n, m, d[3005];
vector<int> g[3005];
bitset<3005> vis;
 
bool flag;
 
constexpr int inf = (long long)1e18 + 7;
 
struct edge {
    int u, v, w;
} e[5005];
 
inline void jpn() {
    d[1] = 0;
    for (int i = 1; i <= n; ++i) {
        flag = false;
        for (int j = 1; j <= m; ++j) {
            if (!vis[e[j].u] && !vis[e[j].v]) continue;
            if (d[e[j].v] > d[e[j].u] + e[j].w and d[e[j].u] < inf) {
                d[e[j].v] = d[e[j].u] + e[j].w;
                flag = true;
            }
 
        }
 
 
    }
 
    return void(0);
}
 
inline void dfs(int node) {
    vis[node] = 1;
    for (auto &to : g[node]) {
        if (!vis[to]) dfs(to);
    }
    return void(0);
}
 
signed main(){
    ios_base::sync_with_stdio(false), cout.tie(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) d[i] = inf;
    for (int i = 1; i <= m; ++i) {
        cin >> e[i].u >> e[i].v >> e[i].w;
        e[i].w = -e[i].w;
        g[e[i].v].emplace_back(e[i].u);
    }
    dfs(n);
    jpn();
    cout << (flag ? -1 : -d[n]) << '\n';
    return 0;
}