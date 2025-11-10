#include "bits/stdc++.h"
using namespace std;
#define int long long
constexpr int sz = 2e5 + 5;
int n, a, b;
void solve(){
    cin >> n >> a >> b;
    vector<double> dp(6 * n + 1, 0.0);
    dp[0] = 1;
    for(int i = 0; i < n; ++i){
        vector<double> new_dp(6 * n + 1, 0.0);
        for(int sm = 0; sm <= 6 * n; ++sm){
            if(dp[sm] > 0){
                for(int j = 1; j <= 6; ++j){
                    new_dp[sm + j] += dp[sm];
                }
            }
        }
        dp = new_dp;
    }
    double ans = 0;
    for(int i = a; i <= b; ++i){
        ans += dp[i];
    }
    ans /= pow(6.0, n);
    cout << fixed << setprecision(6) << ans << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false), cout.tie(0), cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}