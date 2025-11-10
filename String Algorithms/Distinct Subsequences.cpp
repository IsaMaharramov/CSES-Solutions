#include "bits/stdc++.h"
using namespace std;
// #define int long long
constexpr int sz = 2e5 + 5;
constexpr int mod = 1e9 + 7;
 
int n;
string s;
 
void solve(){
  cin >> s;
  n = (int)s.size();
  vector<long long> dp(n + 1);
  dp[0] = 1;
  vector<int> lst(26, -1);
  for(int i = 1; i <= n; ++i){
    int c = s[i - 1] - 'a';
    dp[i] = (dp[i - 1] << 1LL) % mod;
    if(lst[c] != -1){
      dp[i] = (dp[i] - dp[lst[c]] + mod) % mod;
    }
    lst[c] = i - 1;
  }
  cout << (dp[n] - 1 + mod) % mod << '\n';
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