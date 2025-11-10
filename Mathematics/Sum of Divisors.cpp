#include<bits/stdc++.h>
using namespace std;
 
#define int long long
 
constexpr int mod = 1e9 + 7;
 
int n, ans;
 
signed main(){
  ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
 
  cin >> n;
 
  int x(1);
 
  function<int(int, int)> f = [&](int a, int b)->int{
    --a;
    int res(0);
 
    if(b & 1) res = (res + (b % mod) * (((b + 1) >> 1) % mod) % mod) % mod;
    else res = (res + ((b + 1) % mod) * ((b >> 1) % mod) % mod) % mod;
 
 
    if(a & 1) res -= (a % mod) * (((a + 1) >> 1) % mod) % mod;
    else res -= ((a + 1) % mod) * ((a >> 1) % mod) % mod;
    
    while(res < 0) res += mod;
 
    return res % mod;
 
  };
 
  while(x <= n){
 
    int d = n / x;
 
 
    int l(x), r(n), best(x);
 
    while(l <= r){
 
      int mid = l + ((r - l) >> 1);
 
      if((n / mid) ^ d){
        r = mid - 1;
      }else{
        l = mid + 1, best = mid;
      }
 
    }
 
  //  cout << x << ' ' << best << ' ' << d << '\n';
 
    ans = (ans + f(x, best) * (d % mod) % mod) % mod;
 
    x = best + 1;
 
 
 
 
  }
 
  cout << ans << '\n';
 
}