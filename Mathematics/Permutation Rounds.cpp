#include "bits/stdc++.h"
using namespace std;

#define int long long

constexpr int mod = 1e9 + 7;

int qpow(int a, int b){
    int res = 1;
    a %= mod;
    while(b){
        if(b & 1) res = res * a % mod;
        a = (b >>= 1, a * a % mod);
    }
    return res % mod;
}

void solve(){
    int n = (cin >> n, n);
    vector<int> p(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> p[i];
    }
    if(!n) return puts("1"), void(0);
    map<int, int> mxp;
    vector<bool> vis(n + 1, false);
    for(int i = 1; i <= n; ++i){
        if(!vis[i]){
            int cur = i, cl = 0;
            loop:
                vis[cur] = true;
                cur = (++cl, p[cur]);
            if(cur ^ i) goto loop;
            int tmpl = cl;
            for(int q = 2; q * q <= tmpl; ++q){
                if(tmpl % q == 0){
                    int exp = 0;
                    while(tmpl % q == 0){
                        tmpl /= q;
                        ++exp;
                    }
                    mxp[q] = max(mxp[q], exp);
                }
            }
            if(tmpl > 1){
                mxp[tmpl] = max(mxp[tmpl], 1ll);
            }
        }
    }
    int res = 1;
    for(const auto& to : mxp){
        res = res * qpow(to.first, to.second) % mod;
    }
    cout << res << '\n';
    return;
}

signed main(){
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}