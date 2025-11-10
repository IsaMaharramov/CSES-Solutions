#include "bits/stdc++.h"
#define SPEED ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0)
#define int long long
using namespace std;
 
constexpr int sz = 2e5 + 5;
 
int f(int n){
  if(!n) return 0;
  int b(0ll);
  while((1LL << (b + 1)) <= n){
    ++b;
  }
  /// 2 ^ b <= n <= 2^(b + 1)
  int m = n - (1LL << b);
  return (b * (1LL << (b - 1))) + (m + 1) + f(m); 
}
 
signed main(){
  SPEED;
  int n = (cin >> n, n);
  cout << f(n) << '\n';
  return 0;
}