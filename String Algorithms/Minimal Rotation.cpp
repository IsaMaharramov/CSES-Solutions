#include "bits/stdc++.h"
using namespace std;
// #define int long long
constexpr int sz = 2e5 + 5;
constexpr int mod = 1e9 + 7;
 
int f_mr(const string &s){
  string t = s + s;
  int k(0), n = (int)t.size();
  vector<int> f(n, -1);
  for(int i=1; i<n; ++i){
    int j = f[i-k-1];
    while(j!=-1 and t[i]!=t[k+j+1]){
      if(t[i] < t[k+j+1]) k = i - j - 1;
      j = f[j];
    }
    if(t[i] != t[k+j+1]){
      if(t[i]<t[k]) k = i;
      f[i-k]=-1;
    }else{
      f[i-k]=j+1;
    }
  }
  return k;
}
 
string s;
 
void solve(){
  cin >> s;
  int x = f_mr(s);
  cout << s.substr(x) + s.substr(0, x) << '\n';
}
 
signed main(){
  cout.tie(0)->sync_with_stdio(0);
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  //cin >> t;
  while(t--) solve();
  return 0;
}