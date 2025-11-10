#include "bits/stdc++.h"
using namespace std;
// #define int long long
constexpr int sz = 1e7 + 7;
constexpr int mod = 1e9 + 7;
 
string s;
 
bool ask(int i, int j){
  cout << "?" << i << ' ' << j << endl;
  cin >> s;
  return (s[0] == 'Y');
}
 
int n, a[sz], b[sz];
 
void solve(){
  cin >> n;
  for(int i = 1; i <= n; ++i) a[i] = i;
  stable_sort(a + 1, a + n + 1, [&](int i, int j){
    return ask(i, j);
  });
  for(int i = 1; i <= n; ++i) b[a[i]] = i;
  cout << "! ";
  for(int i = 1; i <= n; ++i) cout << b[i] << ' ';
  cout << endl;
}
 
signed main(){
  // cout.tie(0)->sync_with_stdio(0);
  // cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  //cin >> t;
  while(t--) solve();
  return 0;
}
