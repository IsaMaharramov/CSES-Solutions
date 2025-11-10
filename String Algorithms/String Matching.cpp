#include "bits/stdc++.h"
using namespace std;
// #define int long long
constexpr int sz = 2e5 + 5;
constexpr int mod = 1e9 + 7;
 
vector<int> pref_f(const string &s){
  int n = (int)s.size();
  vector<int> p(n);
  for(int i = 1; i < n; ++i){
    int j = p[i - 1];
    while(j > 0 and s[i] != s[j]) j = p[j - 1];
    j += (s[i] == s[j]);
    p[i] = j;
  }
  return p;
}
 
string a, b;
 
void solve(){
  cin >> a >> b;
  string c = b + '#' + a;
  vector<int> p = pref_f(c);
  int cnt(0), m = (int)b.size();
  for(int i = m + 1; i < (int)c.size(); ++i){
    cnt += (p[i] == m);
  }
  cout << cnt << '\n';
}
 
signed main(){
  cout.tie(0)->sync_with_stdio(0);
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  //cin >> t;
  while(t--) solve();
  return 0;
}