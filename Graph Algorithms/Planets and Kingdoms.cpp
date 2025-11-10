#include "bits/stdc++.h"
// #include <chrono>
// #include <thread>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define intt long long
// #define int intt
#define eb emplace_back
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<intt,intt>
#define ld long double
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) x.begin(), x.end()
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
constexpr int sz = 1e5 + 5;
 
int n, m, comp, id[sz];
vector<int> g[sz], gr[sz];
vector<int> otos;
bitset<sz> vis;
 
 
inline void dfs(int u){
  vis[u] = 1;
  for(auto &to : g[u]){
    if(vis[to]) continue;
    dfs(to);
  }
  otos.eb(u);
  return;
}
 
inline void dfs2(int u){
 
  vis[u] = 1;
  id[u] = comp;
 
  for(auto &to : gr[u]){
    if(vis[to]) continue;
 
    dfs2(to);
 
  }
 
  return;
}
 
 
signed main(){
  
  cin >> n >> m;
 
  for(int i = 1, u, v; i <= m; ++i){
    cin >> u >> v;
    g[u].eb(v);
    gr[v].eb(u);
  }
 
  for(int i = 1; i <= n; ++i){
    if(!vis[i]) dfs(i);
  }
 
  reverse(all(otos));
 
  vis.reset();
 
  for(auto &j : otos){
 
    if(vis[j]) continue;
 
    ++comp;
 
    dfs2(j);
 
 
 
  }
 
 
  cout << comp << '\n';
 
  for(int i = 1; i <= n; ++i){
    cout << id[i] << " \n"[i==n];
  }
 
 
}