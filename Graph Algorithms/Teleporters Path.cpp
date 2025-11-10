#include "bits/stdc++.h" 
using namespace std;
 
// #define int long long
// constexpr int inf = 1e18 + 7;
// constexpr int mod = 1e9 + 7;
 
constexpr int sz = 1e5 + 5;
 
vector<int> g[sz];
int indeg[sz], outdeg[sz];
 
void solve(){
    int N, M;
    cin >> N >> M;
    for(int i = 0, u, v; i < M; ++i){
        cin >> u >> v;
        g[u].emplace_back((indeg[v]++, outdeg[u]++, v));
    }
 
    if((outdeg[1] - indeg[1] != 1) or (indeg[N] - outdeg[N] != 1)) return puts("IMPOSSIBLE"), void(0);
 
    for(int i = 2; i < N; ++i) if(indeg[i] ^ outdeg[i]) return puts("IMPOSSIBLE"), void(0);
 
    stack<int> ns;  /// https://en.wikipedia.org/wiki/Eulerian_path
    vector<int> path;
    ns.push(1);
 
    while(!ns.empty()){
        int cur = ns.top();
        if(g[cur].empty()){
            path.emplace_back(cur);
            ns.pop();
        }else{
            int nxt = g[cur].back();
            g[cur].pop_back();
            ns.push(nxt);
        }
    }
 
    if((int)path.size() ^ (M + 1)) return puts("IMPOSSIBLE"), void(0);
 
    reverse(path.begin(), path.end());
 
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