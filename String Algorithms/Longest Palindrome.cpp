#include "bits/stdc++.h"
using namespace std;
// #define int long long
constexpr int sz = 2e5 + 5;
constexpr int mod = 1e9 + 7;
 
string f(const string &s){
  string t = "#";
  for(auto ch : s){
    t += ch;
    t += '#';
  }
  int n = (int)t.size();
  vector<int> p(n, 0);
  int m(0), r(0), mxl(0), xi(0);
 
  for(int i=0; i<n; ++i){
    int y = (m << 1) - i;
    if(i < r) p[i] = min(r - i, p[y]);
    while(i-p[i]-1>=0 and i+p[i]+1<n and t[i-p[i]-1] == t[i+p[i]+1]) ++p[i];
    if(i+p[i] > r) m = (r = i+p[i], i);
    if(p[i] > mxl) mxl = (xi = ((i - p[i]) >> 1), p[i]);
  }
  return s.substr(xi, mxl);
}
 
string s;
 
void solve(){
  cin >> s;
  cout << f(s) << '\n';
}
 
signed main(){
  cout.tie(0)->sync_with_stdio(0);
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  //cin >> t;
  while(t--) solve();
  return 0;
}