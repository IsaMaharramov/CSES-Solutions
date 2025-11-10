#include "bits/stdc++.h"
// #include <chrono>
// #include <thread>
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
#define SPEED ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define vi vector<int>
#define eb emplace_back
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int sz = 2e5+5;
const int inf = 2e18+7;
const int mod = 1e9 + 7;
int i,j;
int n;
int qw(int a, int b){
    int res = 1;
    while(b){
        if(b & 1) res = (--b, res * a % mod);
        else a = (b >>= 1, a * a % mod);
    }
    return res%mod;
}
int inv(int x){ return qw(x, mod - 2) % mod; }
#define vvi vector<vi>
vvi ml(vvi x, vvi y){
    vvi res(n, vi(n, inf));
    for (int j = 0; j < n; ++j){
        for (int k = 0; k < n; ++k) {
            for (int l = 0; l < n; ++l) res[j][k] = min(res[j][k], x[j][l] + y[l][k]);
        }
    }
    return res;
}
vvi qpow(vvi x, int p){
    if(p == 1) return x;
    vvi u = qpow(x, p >> 1);
    u = ml(u, u);
    if (p & 1) u = ml(u, x);
    return u;
}
int m, k;
void solve(){
    cin >> n >> m >> k;
    vvi a(n, vi(n, inf));
    for(int i = 0, u, v, c; i < m; ++i){
        cin >> u >> v >> c;
        --u, --v;
        a[u][v] = min(a[u][v], c);
    }
    int ans = qpow(a, k)[0][n - 1];
    cout << (ans == inf ? -1 : ans) << '\n';
}
signed main(){
    SPEED;
    int TT{1};
    //cin >> TT;
    while(TT--) solve();
    return 0;
}