#include "bits/stdc++.h" 
using namespace std;
 
// #define int long long
// constexpr int inf = 1e18 + 7;
 
constexpr int mod = 1e9 + 7;
 
void solve(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> g(N);
    for(int i = 0, u, v; i < M; ++i){
        cin >> u >> v;
        g[u - 1].emplace_back(v - 1);
    }
 
    int tot_states = (1 << N);
    vector<vector<long long>> dp(tot_states, vector<long long>(N, 0ll));
 
    dp[1][0] = 1;
 
    for(int mask = 0; mask < tot_states; ++mask){
        for(int i=0; i < N; ++i){
            if(dp[mask][i] == 0 or (i == N - 1)) continue;
            for(auto &to : g[i]){
                if((1 << to) & mask) continue;
                int toto = mask | (1 << to);
                dp[toto][to] = (dp[toto][to] + dp[mask][i]) % mod;
            }
        }
    }
 
    cout << dp[tot_states - 1][N - 1] << '\n';
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