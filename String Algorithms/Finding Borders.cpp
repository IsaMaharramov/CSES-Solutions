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
 
int n;
string s;
 
void solve(){
  cin >> s;
  n = (int)s.size();
  vector<int> p = pref_f(s);
  vector<int> tp;
  int k = p[n - 1];
  while(k > 0) k = (tp.emplace_back(k), p[k - 1]);
  sort(tp.begin(), tp.end());
  for(int &to : tp) cout << to << ' ';
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