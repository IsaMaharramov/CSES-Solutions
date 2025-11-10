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
#define int ll
const ll MOD = 1e9 + 7;
const ll mod = (1ll << 31) - 1;
using namespace std;
mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());
constexpr int sz = 1e5 + 5;
constexpr int inf = 1e18 + 7;
 
void show(vector<int>& em){
    for(int &j : em) cout << j << ' ';
    cout << endl;
}
 
int n, m;
vector<pii> g[sz]; 
int d[sz], num[sz], mx[sz], mn[sz];
 
void solve(){
    cin >> n >> m;
    for(int i = 1, u, v, c; i <= m; ++i){
        cin >> u >> v >> c;
        g[u].eb(pii{v, c});
    }
 
    for(int i = 0; i <= n; ++i){
        d[i] = inf;
        mx[i] = -inf;
        mn[i] = inf;
    }
 
    priority_queue<pii, vector<pii>, greater<pii>> q;
 
    q.push({0ll, 1});
    d[1] = 0ll;
    num[1] = 1;
    mn[1] = 0;
    mx[1] = 0;
    while(!q.empty()){
        pii cur = q.top();
        q.pop();
 
        if(d[cur.S] != cur.F) continue;
 
        for(pii &to : g[cur.S]){
 
            if(d[cur.S] + to.S < d[to.F]){
                d[to.F] = d[cur.S] + to.S;
                num[to.F] = num[cur.S];
                mn[to.F] = mn[cur.S] + 1;
                mx[to.F] = mx[cur.S] + 1;
                q.push({d[to.F], to.F});
            }else if((d[cur.S] + to.S) == d[to.F]){
                num[to.F] = (num[to.F] + num[cur.S]) % MOD;
                mn[to.F] = min(mn[to.F], mn[cur.S] + 1);
                mx[to.F] = max(mx[to.F], mx[cur.S] + 1);
            }
        }
    }
    cout << d[n] << ' ' << num[n] << ' ' << mn[n] << ' ' << mx[n] << '\n';
    return;
}
 
signed main(){
    SPEED;
    solve();
    return 0;
}