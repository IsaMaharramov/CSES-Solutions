/// https://en.wikipedia.org/wiki/Burnside%27s_lemma
/// https://cp-algorithms.com/combinatorics/burnside.html
#include "bits/stdc++.h"
using namespace std;
#define int long long
#define eb emplace_back
constexpr int sz = 1e6 + 6;
constexpr int mod = 1e9 + 7;
int extended_euclidean(int a, int b, int &x, int &y){
    if(a == 0){
        x = 0, y = 1;
        return b;
    }
    int x1, y1, d = extended_euclidean(b % a, a, x1, y1);
    x = y1 - (b / a) * x1, y = x1;
    return d;
}
int inv(int a, int m){
    int x, y;
    int g = extended_euclidean(a, m, x, y);
    return (g != 1 ? -1 : (x % m + m) % m);
}
int qpow(int base, int exp){
    int res = 1;
    while(exp > 0){
        if(exp & 1) res = (res * base) % mod;
        exp >>= (base = (base * base) % mod, 1);
        }
    return res;
}
int n;
void solve(){
    cin >> n;
    int deg0 = qpow(2, n * n);
    int deg90 = (n & 1 ? qpow(2, (n * n - 1) / 4) * 2 : qpow(2, n * n / 4)) % mod;
    int deg180 = (n & 1 ? qpow(2, (n * n - 1) / 2) * 2 : qpow(2, n * n / 2)) % mod;
    int deg270 = deg90;
    int ans = (deg0 + deg90 + deg180 + deg270) % mod;
    (ans *= inv(4, mod)) %= mod;
    cout << ans << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false), cout.tie(0), cin.tie(0);
    int T{1};
    //cin >> T;
    while(T--) solve();
    return 0;
}