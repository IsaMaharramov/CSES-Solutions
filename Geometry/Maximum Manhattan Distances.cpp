// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include "bits/stdc++.h"
using namespace std;
#define int long long
constexpr int sz = 2e5 + 5;
constexpr int mod = 1e9 + 7;
constexpr int inf = 1e18 + 7;
 
signed main(){
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    int mx_sm = -inf, mn_sm = inf, mx_dif = -inf, mn_dif = inf;
    for(int i = 0, x, y; i < n; ++i){
        cin >> x >> y;
        mx_sm = max(mx_sm, x + y);
        mn_sm = min(mn_sm, x + y);
        mx_dif = max(mx_dif, x - y);
        mn_dif = min(mn_dif, x - y);
        cout << max(mx_sm - mn_sm, mx_dif - mn_dif) << '\n';
    }
    return 0;
}