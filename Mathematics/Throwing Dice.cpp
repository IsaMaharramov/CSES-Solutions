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
const int inf = 2e9+7;
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
    vvi res(6, vi(6));
    for (int j = 0; j < 6; ++j){
        for (int k = 0; k < 6; ++k) {
            for (int l = 0; l < 6; ++l) res[j][k] = (res[j][k] + (x[j][l] * y[l][k]) % mod) % mod;
        }
    }
    return res;
}
vvi qpow(vvi x, int n){
    if(!n){
        vvi res(6, vi(6));
        for(int i = 0; i < 6; ++i) res[i][i] = 1;
        return res;
    }
    vvi u = qpow(x, n/2);
    u = ml(u, u);
    if (n & 1) u = ml(u, x);
    return u;
}
void solve(){
    cin >> n;
    vvi a(6, vi(6));
    for(i = 0; i < 5; ++i) a[i][i + 1] = 1;
    for(i = 0; i < 6; ++i) a[5][i] = 1;
    cout << qpow(a, n)[5][5] << '\n';
}
signed main(){
    SPEED;
    int TT{1};
    //cin >> TT;
    while(TT--) solve();
    return 0;
}