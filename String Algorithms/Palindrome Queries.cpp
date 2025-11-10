#include "bits/stdc++.h"
using namespace std;
// #define int long long
constexpr int sz = 2e5 + 5;
constexpr int mod = 1e9 + 7;
 
struct BIT{
  int n;
  vector<long long> bit;
  
  BIT(int n): n(n), bit(n + 1, 0) {}
 
  inline void update(int i, long long delta){
    for(; i <= n; i += (i & (-i))) bit[i] = (bit[i] + delta + mod) % mod;
  }
  
  inline long long query(int i){
    long long res = 0ll;
    for(; i > 0; i -= (i & (-i))) res = (res + bit[i]) % mod;
    return res;
  }
 
  inline long long get_ans(int l, int r){
    return (query(r) - query(l-1) + mod) % mod;
  }
 
};
 
 
 
int m, n;
string s;
 
const int P = 911382323;
 
long long qpow(long long a, long long b){
  long long res = 1;
  a %= mod;
  while(b){
    if(b & 1) res = res * a % mod;
    a = (b >>= 1, a * a % mod);
  }
  return res;
}
 
void solve(){
  cin >> n >> m >> s;
  vector<long long> pw(n + 10);
  pw[0] = 1ll;
  for(int i = 1; i <= n + 1; ++i) pw[i] = pw[i-1] * P % mod;
 
  BIT fw1(n), fw2(n);
 
  for(int i = 0; i < n; ++i){
    int x = s[i] - 'a' + 1;
    fw1.update(i + 1, x * pw[i] % mod);
    fw2.update(i + 1, x * pw[n - i - 1] % mod);
  }
 
  register int type;
  while(m--){
    cin >> type;
    if(type ^ 1){
      int a, b;
      cin >> a >> b;
      long long h1 = fw1.get_ans(a, b) * qpow(pw[a - 1], mod - 2) % mod;
      long long h2 = fw2.get_ans(a, b) * qpow(pw[n - b], mod - 2) % mod;
      cout << (h1 == h2 ? "YES" : "NO") << '\n';
    }else{
      int k;
      char ch;
      cin >> k >> ch;
      int px = s[k - 1] - 'a' + 1;
      int nx = ch - 'a' + 1;
      s[k - 1] = ch;
      fw1.update(k, (nx - px) * pw[k - 1] % mod);
      fw2.update(k, (nx - px) * pw[n - k] % mod);
    }
  }
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