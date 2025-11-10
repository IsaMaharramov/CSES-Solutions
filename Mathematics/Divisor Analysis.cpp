#include "bits/stdc++.h"
using namespace std;
 
#define int long long
 
constexpr int sz = 1e5 + 5;
constexpr int mod = 1e9 + 7;
 
int n, res1(1), res2(1), res3(1), N(1), pref[sz];
 
array<int, 2> a[sz];
 
inline int bpow(int x, int y){
  int res(1);
  x %= mod;
  while(y){
    if(y & 1) res = (--y, res * x % mod);
    else x = (y >>= 1, x * x % mod);
  }
  return res;
}
 
inline int bpowl(int x, int y){
  int res(1);
  x %= (mod - 1);
  while(y){
    if(y & 1) res = (--y, res * x % (mod - 1));
    else x = (y >>= 1, x * x % (mod - 1));
  }
  return res;
}
 
signed main(){
  ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
  cin >> n;
 
  function<int(array<int, 2>)> f = [&](array<int, 2> X)->int{
    int x{X[0]}, y{X[1]}, res(1);
 
    res = bpow(x, y + 1) - 1;
 
    if(res < 0) res += mod;
 
    res = res * bpow(x - 1, mod - 2) % mod;
 
    return res;
  };
 
 
  bool flag{false};
 
  pref[0] = 1;
 
  for(register int i = 1; i <= n; ++i){
    cin >> a[i][0] >> a[i][1];
    int x{a[i][0]}, y{a[i][1]};
    res1 = res1 * (y + 1) % mod;
    N = N * bpow(x, y) % mod;
    res2 = (++y, res2 * f(a[i]) % mod);
    pref[i] = pref[i-1] * (y % (mod - 1)) % (mod - 1);
  }
 
  for(register int i = 1; i <= n; ++i){
 
    int pw(1);
 
    if(a[i][1] & 1) pw = (a[i][1] % (mod - 1)) * (((a[i][1] + 1) >> 1) % (mod - 1)) % (mod - 1);
    else pw = ((a[i][1] >> 1) % (mod - 1)) * ((a[i][1] + 1) % (mod - 1)) % (mod - 1);
 
    pw = pw * pref[i-1] % (mod - 1);
    
    res3 = bpow(res3, a[i][1] + 1) * bpow(a[i][0], pw) % mod;
 
  }
 
  cout << res1 << ' ' << res2 << ' ' << res3 << '\n';
 
}