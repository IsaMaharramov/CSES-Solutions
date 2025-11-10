#include "bits/stdc++.h" 
using namespace std;
 
struct Edge{
    int to, rev, cap;
};
 
class max_flow{
private:
    int N;
    vector<vector<Edge>> g;
    vector<int> lvl, itr;
 
    bool bfs(int s, int t){
        fill(lvl.begin(), lvl.end(), -1);
        queue<int> q;
        lvl[s] = 0;
        q.push(s);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto &j : g[u]){
                if(j.cap > 0 and lvl[j.to] < 0){
                    lvl[j.to] = lvl[u] + 1;
                    q.push(j.to);
                }
            }
        }
        return (lvl[t] >= 0);
    }
 
    int Dfs(int u, int t, int f){
        if(u == t) return f;
        for(int &i = itr[u]; i < (int)g[u].size(); ++i){
            Edge &e = g[u][i];
            if(e.cap > 0 and lvl[u] < lvl[e.to]){
                int d = Dfs(e.to, t, min(f, e.cap));
                if(d > 0){
                    e.cap -= d;
                    g[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
 
public:
 
    max_flow(int N) : N(N), g(N), lvl(N), itr(N){}
 
    void add_edge(int u, int v, int cap){
        g[u].push_back({v, (int)g[v].size(), cap});
        g[v].push_back({u, (int)g[u].size() - 1, cap});
        return;
    }
 
    int maxflow(int s, int t){
        int res = 0;
        while(bfs(s, t)){
            fill(itr.begin(), itr.end(), 0);
            int ad;
            while((ad = Dfs(s, t, (int)1e9)) > 0) res += ad;
        }
        return res;
    }
 
    void find_it(int u, vector<bool> &vis){
        vis[u] = true;
        for(auto &j : g[u]){
            if(j.cap > 0 and !vis[j.to]){
                find_it(j.to, vis);
            }
        }
    }
 
};
 
void solve(){
    int N, M;
    cin >> N >> M;
    max_flow flw(N + 1);
    vector<pair<int, int>> E;
 
    for(int i = 0, u, v; i < M; ++i){
        cin >> u >> v;
        flw.add_edge(u, v, 1);
        E.emplace_back(pair<int, int>{u, v});
    }
 
    int mn_c = flw.maxflow(1, N);
    cout << mn_c << '\n';
 
 
    vector<bool> vis(N + 1, false);
    flw.find_it(1, vis);
 
    for(auto &e : E){
        int u{e.first}, v{e.second};
        if(vis[u] ^ vis[v]) cout << u << ' ' << v << '\n';
    }
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