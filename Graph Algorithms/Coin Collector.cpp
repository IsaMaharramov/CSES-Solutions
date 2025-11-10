#include "bits/stdc++.h" 
using namespace std;
 
// #define int long long
// constexpr int inf = 1e18 + 7;
// constexpr int mod = 1e9 + 7;
 
constexpr int sz = 1e5 + 5;
 
vector<int> g[sz], gr[sz];
 
void solve(){
    int N, M;
    cin >> N >> M;
    vector<long long> c(N);
    for(long long &j : c) cin >> j;
    for(int i = 0, u, v; i < M; ++i){
        cin >> u >> v;
        g[u].emplace_back(v);
        gr[v].emplace_back(u);
    }
 
    vector<int> vis(N + 1, false);
    vector<int> path;
 
    function<void(int)> Dfs = [&](int node){
        vis[node] = true;
        for(int &to : g[node]) if(!vis[to]) Dfs(to);
        path.emplace_back(node);
    };
 
    for(int i = 1; i <= N; ++i){
        if(!vis[i]) Dfs(i);
    }
 
    reverse(path.begin(), path.end());
 
    vector<int> comp(N + 1, -1);
    int comp_id = 0;
 
    function<void(int)> Dfs_r = [&](int node){
        comp[node] = comp_id;
        for(int &to : gr[node]) if(comp[to] == -1) Dfs_r(to);
    };
    
    for(int &node : path){
        if(comp[node] != -1) continue;
        Dfs_r(node);
        ++comp_id;
    }
 
    int n_comp = comp_id;
 
    vector<long long> c_scc(n_comp, 0ll);
 
    for(int i = 1; i <= N; ++i){
        c_scc[comp[i]] += c[i - 1];
    }
 
    vector<set<int>> rev_dag(n_comp);
    for(int node = 1; node <= N; ++node){
        for(int &to : g[node]){
            if(comp[node] ^ comp[to]){
                rev_dag[comp[to]].insert(comp[node]);
            }
        }
    }
 
 
    vector<vector<int>> original_dag(n_comp);
    for(int i = 0; i < n_comp; ++i){
        for(const int &j : rev_dag[i]){
            original_dag[j].emplace_back(i);
        }
    }
 
    vector<int> indeg(n_comp, 0);
    for(int i = 0; i < n_comp; ++i){
        for(int &j : original_dag[i]){
            indeg[j]++;
        }
    }
 
    queue<int> q;
    for(int i = 0; i < n_comp; ++i){
        if(!indeg[i]){
            q.push(i);
        }
    }
 
 
    vector<int> tp;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        tp.emplace_back(cur);
        for(int &to : original_dag[cur]){
            --indeg[to];
            if(!indeg[to]) q.push(to);
        }
    }
 
    vector<long long> dp(n_comp, 0ll);
    long long ans = 0ll;
    for(int &node : tp){
        dp[node] = c_scc[node];
        for(const int &j : rev_dag[node]){
            dp[node] = max(dp[node], c_scc[node] + dp[j]);
        }
        ans = max(ans, dp[node]);
    }
 
    cout << ans << '\n';
 
    return;
}
 
signed main(){
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}