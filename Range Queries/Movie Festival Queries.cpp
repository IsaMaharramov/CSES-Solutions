#include "bits/stdc++.h"
using namespace std;

#define int long long

constexpr int sz = 2e6 + 5;
constexpr int mod = 1e9 + 7;
constexpr int inf = 1e18 + 7;

int n, q, fa[20][sz], nxt[sz], tp[sz];

void solve(){
    cin >> n >> q;
    fill(tp, tp + sz, inf);
    for(int i = 1, a, b; i <= n; ++i)   tp[a] = (cin >> a >> b, min(tp[a], b));
    nxt[sz - 1] = inf;
    for(int i = sz - 2; i >= 0; --i) nxt[i] = min(nxt[i + 1], tp[i]);
    for(int i = 0; i < sz - 1; ++i) fa[0][i] = nxt[i];
    for(int j = 1; j < 20; ++j){
        for(int i = 0; i < sz - 1; ++i) fa[j][i] = (fa[j - 1][i] < sz - 1 ? fa[j - 1][fa[j - 1][i]] : inf);
    }
    register int a, b;
    while(q--){
        cin >> a >> b;
        int ans{0ll}, x{a};
        for(int j = 19; j >= 0; --j) if(fa[j][x] <= b) x = (ans += (1 << j), fa[j][x]);
        cout << ans << '\n';
    }
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