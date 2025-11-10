#include "bits/stdc++.h"
using namespace std;
 
#define int long long
 
constexpr int mod = (int)1e9 + 7;
 
int ifact[2000005], fact[2000005];
 
inline int C(int n, int k) {
    if (k > n) return 0;
    int res = fact[n];
    res = res * ifact[n - k] % mod;
    res = res * ifact[k] % mod;
    return res;
}
 
inline int bpow(int a, int b) {
    int res(1);
    a %= mod;
    while (b) {
        if (b & 1) res = res * a % mod, --b;
        else a = a * a % mod, b >>= 1;
    }
    return res;
}
 
int n, m;
 
signed main() {
    ios_base::sync_with_stdio(false), cout.tie(0), cin.tie(0);
    fact[0] = ifact[0] = 1;
    for (register int i = 1; i <= 2000005; ++i) {
        ifact[i] = ifact[i - 1] * i % mod;
        fact[i] = ifact[i];
    }
    for (register int i = 1; i <= 2000005; ++i) {
        ifact[i] = bpow(ifact[i], mod - 2);
    }
    cin >> n >> m;
    cout << C(m + n - 1, n - 1) << '\n';
    return 0;
}
