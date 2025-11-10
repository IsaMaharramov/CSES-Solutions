#include "bits/stdc++.h" 
using namespace std;
 
#define int long long
 
constexpr int inf = 1e18 + 7;
 
struct Fast_Flow{
    int N;
    vector<vector<int>> g, cap;
 
    Fast_Flow(int N) : N(N), g(N), cap(N, vector<int>(N, 0ll)){}
 
    void add_edge(int u, int v, int c){
        if(!cap[u][v] and !cap[v][u]){
            g[u].emplace_back(v), g[v].emplace_back(u);
        }
        cap[u][v] += c;
    }
 
    int bfs(int s, int t, vector<int> &fa){
        fill(fa.begin(), fa.end(), -1);
        fa[s] = -2;
        queue<pair<int, int>> q;
        q.push({s, inf});
 
        while(!q.empty()){
            int u{q.front().first}, flw{q.front().second};
            q.pop();
 
            for(int &v : g[u]){
                if(fa[v] == -1 and cap[u][v] > 0){
                    fa[v] = u;
                    int n_flw = min(flw, cap[u][v]);
                    if(v == t){
                        return n_flw;
                    }
                    q.push({v, n_flw});
                }
            }
        }
        return 0;
    }
 
    int max_flow(int s, int t){
        int res = 0;
        vector<int> fa(N);
 
        while(true){
            int n_flw = bfs(s, t, fa);
            if(!n_flw) break;
            res += n_flw;
            int cur = t;
            while(cur != s){
                int p = fa[cur];
                cap[p][cur] -= (cap[cur][p] += n_flw, n_flw);
                cur = p;
            }
        }
 
        return res;
    }
 
};
 
void solve(){
    int N, M;
    cin >> N >> M;
    
    Fast_Flow flow(N + 10);
 
    for(int i = 0, u, v, c; i < M; ++i){
        cin >> u >> v >> c;
        flow.add_edge(u, v, c);
    }
 
    cout << flow.max_flow(1, N) << '\n';
 
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