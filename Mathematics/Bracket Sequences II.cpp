#include "bits/stdc++.h"
using namespace std;
constexpr int sz = 1e6 + 6;
constexpr int mod = 1e9 + 7;
#define int long long
int fact[sz << 1], inv_fact[sz << 1];
int qpow(int a, int b){
    int res = 1;
    while(b){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
void precomp(int n){
    fact[0] = 1;
    for(int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i % mod;
    inv_fact[n] = qpow(fact[n], mod - 2);
    for(int i = n - 1; i >= 0; --i) inv_fact[i] = inv_fact[i + 1] * (i + 1) % mod;
    return;
}
int nCr(int n, int r) {
    if (r < 0 || r > n) return 0ll;
    return ((fact[n] * inv_fact[r] % mod) * inv_fact[n - r]) % mod;
}
int n;
string s;
void solve(){
    cin >> n >> s;
    if(n & 1) return puts("0"), void(0);
    int m = (int)s.size();
    int c = 0, cl = 0, op = 0;
    for(char &ch : s){
        if(ch == '(') ++c, ++op;
        else --c, ++cl;
        if(c < 0) return puts("0"), void(0);
    }
    int r_op = (n >> 1) - op;
    int r_cl = (n >> 1) - cl;
    if(min(r_cl, r_op) < 0 or ((r_cl + r_op) ^ (n - m))) return puts("0"), void(0);
    
    precomp(n - m + 2);
    cout << (nCr(n - m, r_op) - nCr(n - m, r_cl + 1) + mod) % mod;
} 
signed main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T{1};
    //cin >> T;
    for(int t = 0; t < T; ++t) solve();
    return 0;
}