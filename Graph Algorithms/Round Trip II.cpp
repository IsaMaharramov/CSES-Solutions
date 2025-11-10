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
#define OK cerr<<"OK"<<endl<<flush
#define pii pair<int, int>
#define pll pair<ll, ll>
#define eb emplace_back
#define F first
#define S second
#define y0 jfsakf
#define y1 kgvgdwlkgew
#define endl '\n'
const ll MOD = 1e9 + 7;
const ll mod = (1ll << 31) - 1;
using namespace std;
mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());
const int N = 1e5+5;
constexpr int inf = 1e9 + 7;
 
int n, m;
vector<int> g[N];
int p[N], vis[N];
 
void dfs(int node){
    vis[node] = 1;
    for(int &to : g[node]){
        if(vis[to] == 2) continue;
        if(!vis[to]){
            p[to] = node;
            dfs(to);
        }else{
            vector<int> cycle = {to};
            while(node != to){
                cycle.eb(node);
                node = p[node];
            }
            cycle.eb(node);
            reverse(all(cycle));
            cout << (int)cycle.size() << '\n';
            for(int &i : cycle) cout << i << ' ';
            cout << '\n';
            exit(0);
        }
    }
    vis[node] = 2;
}
 
void solve(){
    cin >> n >> m;
    for(int i = 0, u, v; i < m; ++i){
        cin >> u >> v;
        g[u].eb(v);
    }
    for(int i = 1; i <= n; ++i) if(!vis[i]) dfs(i);
    cout << "IMPOSSIBLE" << '\n';
}
 
signed main(){
    SPEED;
    solve();
}