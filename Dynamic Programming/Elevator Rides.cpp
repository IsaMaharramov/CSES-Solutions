#include "bits/stdc++.h"
using namespace std;
#define int long long
#define pii pair<int, int>
#define F first
#define S second
constexpr int sz = 2e5 + 5;
int n, x, w[25];
pii dp[1 << 20 | 1]; // {rides, weight}
void solve(){
    cin >> n >> x;
    for(int i = 0; i < n; ++i){
        cin >> w[i];
    }
    dp[0] = pii{1, 0};
    for(int mask = 1; mask < (1 << n); ++mask){
        dp[mask] = pii{21, 0};
        for(int j = 0; j < n; ++j){
            if((1 << j) & mask){
                int rides = dp[mask ^ (1 << j)].F;
                int W = dp[mask ^ (1 << j)].S;
                if(W + w[j] > x){
                    ++rides;
                    W = min(W, w[j]);
                }else{
                    W += w[j];
                }
                dp[mask] = min(dp[mask], pii{rides, W}); 
            }
        }
    }
    cout << dp[(1 << n) - 1].F << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false), cout.tie(0), cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}