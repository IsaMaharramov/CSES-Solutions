#include "bits/stdc++.h" 
using namespace std;
 
// #define int long long
// constexpr int inf = 1e18 + 7;
// constexpr int mod = 1e9 + 7;
 
constexpr int sz = 1e5 + 5;
 
//vector<int> g[sz];
list<int> g[sz];
 
void solve(){
    int N, M;
    cin >> N >> M;
    vector<int> e_cnt(N + 10, 0);
    for(int i = 0, u, v; i < M; ++i){
        cin >> u >> v;
        g[u].emplace_back(v), g[v].emplace_back(u);
        e_cnt[u]++;
        e_cnt[v]++;
    }
 
    for(int i = 0; i < N; ++i)  if(e_cnt[i] & 1) return puts("IMPOSSIBLE"), void(0);
 
    vector<int> path;
    stack<int> ns;
    ns.push(1);
    while(!ns.empty()){
        int cur = ns.top();
        if(g[cur].empty()){
            path.emplace_back(cur);
            ns.pop();
        }else{
            int nxt = g[cur].front();
            g[cur].pop_front();
 
            for(auto it = g[nxt].begin(); it != g[nxt].end(); ++it){
                if(*it == cur){
                    g[nxt].erase(it);
                    break;
                }
            }
 
            ns.push(nxt);
        }
    }
 
    if((int)path.size() ^ (M + 1)) return puts("IMPOSSIBLE"), void(0);
 
    for(int &node : path) cout << node << ' ';
    cout << '\n';
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