#include "bits/stdc++.h"
using namespace std;
 
constexpr long long inf = 1e18 + 7;
 
int n, a[5005];
long long pref[5005], dp[5005][5005];
 
signed main(){
  ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
  cin >> n;
 
  for(register int i = 1; i <= n; ++i){
    cin >> a[i], pref[i] = pref[i-1] + a[i];
  }
 
  for(register int l = n; l; --l){
    for(register int r = l; r <= n; ++r){
      dp[l][r] = max(pref[r] - pref[l] - dp[l+1][r] + a[l], pref[r-1] - pref[l-1] - dp[l][r-1] + a[r]);
    }
  }
 
  cout << dp[1][n] << '\n';
 
}