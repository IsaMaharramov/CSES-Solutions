#include "bits/stdc++.h"
using namespace std;
// #define int long long
constexpr int sz = 2e5 + 5;
constexpr int mod = 1e9 + 7;
 
int n, k;
 
void solve(){
  cin >> n >> k;
  vector<string> s(n);
  for(int i = 0; i < n; ++i){
    cin >> s[i];
  }
  vector<long long> ans(k, 0ll);
  vector<vector<int>> dp(n, vector<int>(n, 0));
  for(int li = 0; li < k; ++li){
    char ch = 'A' + li;
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < n; ++j){
        if(s[i][j] == ch){
          if(!i or !j){
            dp[i][j] = 1;
          }else{
            dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
          }
          ans[li] += dp[i][j];
        }else{
          dp[i][j] = 0;
        }
      }
    }
  }
  for(int i = 0; i < k; ++i){
    cout << ans[i] << '\n';
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