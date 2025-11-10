// #pragma GCC optimize("O3,unroll-loops,inline")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC target ("avx,avx2,fma")
// #pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define SPEED ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0)
#define rall(v) (v).rbegin(),(v).rend()
#define all(v) (v).begin(),(v).end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define eb emplace_back
#define F first
#define S second
#define y0 jfsakf
#define y1 kgvgdwlkgew
const ll MOD = 1e9 + 7;
const ll mod = (1ll << 31) - 1;
using namespace std;
mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());
constexpr int sz = 1e5 + 5;
constexpr int inf = 1e9 + 7;
 
int n, m;
vector<int> g[sz];
bitset<sz> vis;
 
bool check(int node){
    vis[node] = 1;
    bool flag = (node == n);
    for(int &i : g[node]){
        if(vis[i]) continue;
        flag |= check(i);
    }
    return flag;
}
 
int dp[sz], to[sz];
 
int dfs(int node){
 
    if(node == n) return dp[n] = 1;
 
    if(dp[node] != -1) return dp[node];
 
    int mx(0);
 
    for(int &i : g[node]){
 
        int tmp = dfs(i);
 
        if(tmp) ++tmp;
 
        if(tmp > mx){
            mx = tmp;
            to[node] = i;
        }
 
 
 
 
    }
 
 
    return dp[node] = mx;
}
 
 
void solve(){
    cin >> n >> m;
    for(int i = 1, u, v; i <= m; ++i){
        cin >> u >> v;
        g[u].eb(v);
    }
    if(!check(1)){
        cout << "IMPOSSIBLE" << '\n';
        return;
    }
    for(int i = 0; i <= n; ++i){
        to[i] = i;
        dp[i] = -1;
    }
 
 
    dfs(1);
    vector<int> v;
    int tot = 1;
   // cout<<to[tot];
  //  return;
    while(tot != n){
        v.eb(tot);
        tot = to[tot];
    }
 
    v.eb(tot);
    cout << (int)v.size() << '\n';
    for(int &i : v){
        cout << i << ' ';
    }
    cout << '\n';
    return;
}
 
signed main(){
    SPEED;
    solve();
    return 0;
}