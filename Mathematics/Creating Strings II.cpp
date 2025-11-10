#include "bits/stdc++.h"
using namespace std;
 
#define int long long
 
constexpr int mod = (int)1e9 + 7;
 
int ifact[1000005], fact[1000005];
 
inline int bpow(int a, int b) {
    int res(1);
    a %= mod;
    while (b) {
        if (b & 1) res = res * a % mod, --b;
        else a = a * a % mod, b >>= 1;
    }
    return res;
}
 
int n, a, b, c[26];
 
signed main() {
    ios_base::sync_with_stdio(false), cout.tie(0), cin.tie(0);
    fact[0] = ifact[0] = 1;
    for (register int i = 1; i <= 1000000; ++i) {
        ifact[i] = ifact[i - 1] * i % mod;
        fact[i] = ifact[i];
    }
    for (register int i = 1; i <= 1000000; ++i) {
        ifact[i] = bpow(ifact[i], mod - 2);
    }
    string s;
    cin >> s;
    int n = (int)s.size();
    for (int i = 0; i < n; ++i) {
        c[s[i] - 'a']++;
    }
    int ans = fact[n];
    for (int i = 0; i < 26; ++i) {
        ans = ans * ifact[c[i]] % mod;
    }
    cout << ans << '\n';
    return 0;
}