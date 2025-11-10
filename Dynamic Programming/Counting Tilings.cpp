#include "bits/stdc++.h"
using namespace std;
#define int long long
constexpr int sz = 2e5 + 5;
constexpr int mod = 1e9 + 7;
 
int n, m;
int dp[1005][11][1 << 11];
 
void solve(){
    cin >> n >> m;
    dp[0][n][0] = 1;
    
    for(int i = 1; i <= m; ++i){
 
        for(int mask = 0; mask < (1 << n); ++mask){
            dp[i][0][mask] = dp[i-1][n][mask];
        }
 
        for(int j = 1; j <= n; ++j){
            for(int mask = 0; mask < (1 << n); ++mask){
 
                if((1 << j - 1) & mask){
                    dp[i][j][mask] += dp[i][j - 1][mask - (1 << j - 1)];
                }else{
                    dp[i][j][mask] += dp[i][j - 1][mask + (1 << j - 1)];
 
                    if((j > 1) && !((1 << j - 2) & mask)) dp[i][j][mask] += dp[i][j - 2][mask];
                
                }
 
 
                dp[i][j][mask] %= mod;
 
            }
        }
 
 
    }
 
 
 
    cout << dp[m][n][0] << '\n';
 
}
 
signed main(){
    ios_base::sync_with_stdio(false), cout.tie(0), cin.tie(0);
    int T{1};
    //cin >> T;
    while(T--) solve();
    return 0;
}