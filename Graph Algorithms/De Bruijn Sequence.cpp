#include "bits/stdc++.h" 
using namespace std;
 
// #define int long long
// constexpr int inf = 1e18 + 7;
// constexpr int mod = 1e9 + 7;
 
constexpr int sz = 1e5 + 5;
 
void solve(){
    int N = (cin >> N, N);    
    
    if(N == 1) return puts("01"), void(0);
 
    int tot = (1 << (N - 1));
    vector<vector<int>> g(tot);
 
    register int node = 0;
    loop:
        int x = (node << 1) & (tot - 1);
        g[node].emplace_back(x);
        g[node++].emplace_back(x | 1);
    if(node < tot) goto loop;
 
    vector<int> path;
    stack<int> ns;
    ns.push(0);
 
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
 
    reverse(path.begin(), path.end());
 
    string ans = "";
    for(int i = 1; i < (int)path.size(); ++i){
        ans += (path[i] & 1 ? '1' : '0');
    }
 
    cout << string(N - 1, '0') + ans << '\n';
 
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