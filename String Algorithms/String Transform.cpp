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
 
  vector<int> cnt(1 << 8, 0);
  for(char ch : s) cnt[ch]++;
 
  vector<int> st(1 << 8, 0);
  int sm(0);
  for(int i = 0; i < (1 << 8); ++i){
    if(cnt[i] > 0){
      st[i] = sm;
      sm += cnt[i];
    }
  }
 
  vector<int> occ(n);
  vector<int> vis(1 << 8, 0);
  for(int i = 0; i < n; ++i){
    char ch = s[i];
    occ[i] = st[ch] + vis[ch];
    vis[ch]++;
  }
 
 
  string res = "";
  int r = find(s.begin(), s.end(), '#') - s.begin();
  for(int i = 0; i < n - 1; ++i){
    r = occ[r];
    res += s[r];
  }
  reverse(res.begin(), res.end());
  cout << res << '\n';
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