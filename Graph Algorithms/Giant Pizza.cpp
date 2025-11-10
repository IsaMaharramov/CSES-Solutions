#include "bits/stdc++.h" 
using namespace std;
 
// #define int long long
// constexpr int inf = 1e18 + 7;
// constexpr int mod = 1e9 + 7;
 
constexpr int sz = 2e5 + 5;
 
vector<int> g[sz];
int dt[sz], lw_lnk[sz], scc_id[sz], scc_cnt, cur_t;
bool on_stack[sz];
stack<int> ns;
 
int get_negation(int node, int m){
    return (node <= m ? node + m : node - m);
}
 
int get_node(char type, int val, int m){
    return (type == '+' ? val : val + m);
}
 
void tarjan_dfs(int u, int m){
    dt[u] = lw_lnk[u] = ++cur_t;
    ns.push(u);
    on_stack[u] = true;
    for(auto &v : g[u]){
        if(!dt[v]){
            tarjan_dfs(v, m);
            lw_lnk[u] = min(lw_lnk[u], lw_lnk[v]);
        }else if(on_stack[v]){
            lw_lnk[u] = min(lw_lnk[u], dt[v]);
        }
    }
 
    if(lw_lnk[u] == dt[u]){
        ++scc_cnt;
        while(true){
            int cur = ns.top();
            ns.pop();
            on_stack[cur] = false;
            scc_id[cur] = scc_cnt;
            if(u == cur) break;
        }
    }
    return;
}
 
void solve(){
    int N, M, v1, v2;
    cin >> N >> M;
    char t1, t2;
    for(int i = 0; i < N; ++i){
        cin >> t1 >> v1 >> t2 >> v2;
        array<int, 2> node = {get_node(t1, v1, M), get_node(t2, v2, M)};
        array<int, 2> neg_node = {get_negation(node[0], M), get_negation(node[1], M)};
        g[neg_node[0]].emplace_back(node[1]), g[neg_node[1]].emplace_back(node[0]);
    }
 
    for(int i = 1; i <= (M << 1); ++i){
        if(!dt[i]) tarjan_dfs(i, M);
    }
    
    for(int i = 1; i <= M; ++i){
        int np = i, nm = i + M;
        if(scc_id[np] == scc_id[nm]) return puts("IMPOSSIBLE"), void(0);
    } 
 
    string res = "";
    for(int i = 1; i <= M; ++i){
        res += ((scc_id[i] < scc_id[i + M]) ? "+ " : "- ");
    }
 
    cout << res << '\n';
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