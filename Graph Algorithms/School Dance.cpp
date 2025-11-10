#include "bits/stdc++.h" /// https://en.wikipedia.org/wiki/Hopcroft%E2%80%93Karp_algorithm
using namespace std;
 
class BipartiteMatching{
private:
    int N, M;
    vector<vector<int>> g;
    vector<int> match_L, match_R;
    vector<bool> vis;
 
    bool dfs(int u){
        if(vis[u]) return false;
        vis[u] = 1;
        for(auto &v : g[u]){
            if(match_R[v] == -1 or dfs(match_R[v])){
                match_L[u] = v;
                match_R[v] = u;
                return true;
            }
        }
        return false;
    }
 
public:
    BipartiteMatching(int N, int M) : N(N), M(M), g(N + 1), match_L(N + 1, -1), match_R(M + 1, -1){}
 
    void add_edge(int u, int v){
        g[u].emplace_back(v);
    }
 
    int max_matching(){
        int res = 0;
        bool flag = true;
        while(flag){
            flag = false;
            vis.assign(N + 1, false);
            for(int i = 1; i <= N; ++i){
                if(match_L[i] == -1 and dfs(i)){
                    ++res;
                    flag = true;
                }
            }
        }
        return res;
    }
 
    void get_ans(){
        for(int i = 1; i <= N; ++i){
            if(match_L[i] != -1){
                cout << i << ' ' << match_L[i] << '\n';
            }
        }
    }
 
};
 
void solve(){
    int N, M, K;
    cin >> N >> M >> K;
    
    BipartiteMatching b_m(N, M);
 
    for(int i = 0, u, v; i < K; ++i){
        cin >> u >> v;
        b_m.add_edge(u, v);
    }
 
    cout << b_m.max_matching() << '\n';
    b_m.get_ans();
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