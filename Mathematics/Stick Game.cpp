#include "bits/stdc++.h"
using namespace std;
#define int long long
constexpr int sz = 1e6 + 5;
int n, k, p[sz];
bitset<sz> dp;
void solve(){
    cin >> n >> k;
    for(int i = 1; i <= k; ++i){
        cin >> p[i];
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= k; ++j){
            if(i >= p[j]) dp[i] = dp[i] | !dp[i - p[j]];
        }
    }
    for(int i = 1; i <= n; ++i) cout << (dp[i] ? 'W' : 'L');
    cout << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false), cout.tie(0), cin.tie(0);
    int T{1};
    //cin >> T;
    while(T--) solve();
    return 0;
}