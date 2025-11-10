#include "bits/stdc++.h"
#include <chrono>
#include <thread>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define intt long long
#define int intt
#define pb push_back
#define endl '\n'
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<intt,intt>
#define ld long double
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define vi vector<int>
#define eb emplace_back
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int sz = 2e5+5;
const int sz1 = 2005;
const int inf = 2e9+7;
const intt infl = 1e18;
const ld eps = 1e-9;
const int mod = 1e9+7;
int i,j;
int n, h[sz], ans = -inf, dp[sz];
 
vi g[sz];
 
void solve(){
    cin >> n;
    for(i = 1; i <= n; ++i){
        cin >> h[i];   
    }
    stack<pii> st;
    for(i = 1; i <= n; ++i){
        while(!st.empty() and st.top().S < h[i]){
            g[i].eb(st.top().F);
            st.pop();
        }
        st.push({i, h[i]});
    }
    while(!st.empty()) st.pop();
    for(i = n; i; --i){
        while(!st.empty() and st.top().S < h[i]){
            g[i].eb(st.top().F);
            st.pop();
        }
        st.push({i, h[i]});
    }
    function<int(int)> Dfs = [&](int node)->int{
        if(dp[node]) return dp[node];
        for(int &to : g[node]) dp[node] = max(dp[node], Dfs(to) + 1);
        return dp[node];
    };
    for(int u = 1; u <= n; ++u){
        ans = max(ans, Dfs(u));
    }
    cout << ans + 1 << '\n';
}
signed main(){
    fastio;
    int t = 1;
    //cin >> t;
    for ( int cs = 1; cs <= t; cs++ ) {
        solve();
    }
    return 0;
}