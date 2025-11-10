#include "bits/stdc++.h"
using namespace std;
// #define int long long
constexpr int sz = 2e5 + 5;
constexpr int mod = 1e9 + 7;
 
int m, n;
string s;
 
void solve(){
  cin >> n >> s;
  m = (int)s.size();
 
  vector<int> p(m);
  for(int i=1; i<m; ++i){
    int j = p[i-1];
    while(j and s[i]!=s[j]) j = p[j-1];
    j += (s[i]==s[j]);
    p[i] = j;
  }
 
  vector<vector<int>> nxt(m + 1, vector<int>(26));
  for(int i=0; i <= m; ++i){
    for(int c = 0; c < 26; ++c){
      if(i==m){
        nxt[i][c]=m;
        continue;
      }
      char ch = 'A' + c;
      int j = i;
      while(j and s[j]!=ch) j = p[j-1];
      j += (s[j]==ch);
      nxt[i][c]=j;
    }
  }
 
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  dp[0][0] = 1;
 
  long long ans = 0ll;
 
  for(int i=0; i<n; ++i){
    for(int j=0; j<=m; ++j){
      if(!dp[i][j]) continue;
      for(int c = 0; c<26; ++c){
        int nj = nxt[j][c];
        if(nj == m) ans = (ans + dp[i][j]) % mod;
        else dp[i + 1][nj] = (dp[i + 1][nj] + dp[i][j]) % mod;
      }
    }
  }
 
  long long tot{1};
  for(int i=0; i<n; ++i) tot  = tot*26%mod;
  long long bad(0ll);
  for(int j=0; j<m; ++j) bad = (bad+dp[n][j])%mod;
 
  cout << (tot - bad + mod) % mod << '\n';
 
 
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