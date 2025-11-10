#include "bits/stdc++.h"
using namespace std;
// #define int long long
// constexpr int inf = 1e18 + 7;
constexpr int sz = 2e5 + 5;
constexpr int mod = 1e9 + 7;

int n, t[sz], cnt, d[sz];
bitset<sz> vis;
queue<int> q;

void solve(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> t[i];
        t[i]--;
    }
    function<void(int)> Dfs = [&](int node){
        q.push(node);
        if(vis[node]) return cnt += d[node], void(0);
        vis[node] = (++cnt, 1);
        Dfs(t[node]);
        return;
    };
    for(int i = 0; i < n; ++i){
        if(vis[i]) continue;
        cnt = 0;
        Dfs(i);
        int tot(1);
        while(!q.empty()){
            if(q.front() == q.back()) tot = 0;
            d[q.front()] = cnt;
            cnt -= tot;
            q.pop();
        }
    }
    for(int i = 0; i < n; ++i) cout << d[i] << ' ';
    cout << '\n';
    return;
}
 
signed main(){
    ios_base::sync_with_stdio(false), cout.tie(0), cin.tie(0);
    int T{1};
    //cin >> T;
    while(T--) solve();
    return 0;
}