#include "bits/stdc++.h"
using namespace std;
// #define int long long
constexpr int sz = 2e5 + 5;
constexpr int mod = 1e9 + 7;
 
vector<int> Z(const string &s){
  int n = (int)s.size();
  vector<int> z(n);
  int l(0), r(0);
  for(int i = 1; i < n; ++i){
    if(i <= r) z[i] = min(r - i + 1, z[i - l]);
    while(i + z[i] < n and s[z[i]] == s[i + z[i]]) z[i]++;
    if(i + z[i] - 1 > r) l = (r = i + z[i] - 1, i);
  }
  z[0] = 0;
  return z;
}
 
vector<int> PI(const string &s){
  int n = (int)s.size();
  vector<int> pi(n);
  for(int i = 1; i < n; ++i){
    int j = pi[i - 1];
    while(j > 0 and (s[i] ^ s[j])) j = pi[j - 1];
    j += (s[i] == s[j]);
    pi[i] = j;
  }
  return pi;
}
 
string s;
 
void solve(){
  cin >> s;
 
  vector<int> z = Z(s);
  vector<int> pi = PI(s);
 
  for(int i = 0; i < (int)z.size(); ++i) cout << z[i] << " \n"[i == (int)z.size() - 1];
  for(int i = 0; i < (int)pi.size(); ++i) cout << pi[i] << " \n"[i == (int)pi.size() - 1];
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