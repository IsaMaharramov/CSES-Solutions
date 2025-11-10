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
int indegree[sz], dp[sz];
 
void show(vector<int>& em){
    for(int &j : em) cout << j << ' ';
    cout << endl;
}
 
void solve(){
    cin >> n >> m;
    for(int i = 1, u, v; i <= m; ++i){
        cin >> u >> v;
        g[u].eb(v);
        indegree[v]++;
    }
    queue<int> q;
    for(int i = 1; i <= n; ++i){
        if(indegree[i]) continue;
        q.push(i);
    }
 
    dp[1] = 1;
 
    while(!q.empty()){
        int cur = q.front();
        q.pop();
 
        for(int &i : g[cur]){
            --indegree[i];
 
            dp[i] = (dp[i] + dp[cur]) % MOD;
            if(indegree[i] == 0){
                q.push(i);
            }
        }
    }
    cout << dp[n] << '\n';
}
 
signed main(){
    SPEED;
    solve();
    return 0;
}
