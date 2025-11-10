#include "bits/stdc++.h"
using namespace std;
// #define int long long
constexpr int sz = 2e5 + 5;
constexpr int mod = 1e9 + 7;
 
struct Node{
  array<int, 26> nxt;
  bool e;
  Node(){
    nxt.fill(-1);
    e = false;
  }
};
 
int n, k, dp[sz];
string s;
 
void solve(){
  cin >> s >> k;
  n = (int)s.size();
  vector<Node> trie(1);
  for(int i = 0; i < k; ++i){
    string w;
    cin >> w;
    int node = 0;
    for(char ch : w){
      int j = ch - 'a';
      if(trie[node].nxt[j] == -1){
        trie[node].nxt[j] = (int)trie.size();
        trie.emplace_back();
      }
      node = trie[node].nxt[j];
    }
    trie[node].e = true;
  }
  dp[0] = 1;
  for(int i = 0, node; i < n; ++i){
    if(!dp[i]) continue;
    node = 0;
    for(int j = i; j < n; ++j){
      int jj = s[j] - 'a';
      if(trie[node].nxt[jj] == -1) break;
      node = trie[node].nxt[jj];
      if(trie[node].e){
        dp[j + 1] += dp[i];
        if(dp[j + 1] >= mod) dp[j + 1] -= mod;
      }
    }
  }
  cout << dp[n] << '\n';
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