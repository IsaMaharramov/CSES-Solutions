#include "bits/stdc++.h"
using namespace std;
 
constexpr int sz = 2e5 + 5;
 
#define int long long
 
signed main(){
  cout.tie(0)->sync_with_stdio(0);
  cin.tie(0)->sync_with_stdio(0);
  int N = (cin >> N, N);
  const int MX_BITS = 30;
  vector<int> B(MX_BITS, 0);
  for(int i = 0, X; i < N; ++i){
    cin >> X;
    for(int b = MX_BITS; b >= 0; --b){
      if(!((1LL << b) & X)) continue;
      if(!B[b]){
        B[b] = X;
        break;
      }
      X ^= B[b];
    }
  }
  int mx_xor_sm{0ll};
  for(int b = MX_BITS - 1; b >= 0; --b) mx_xor_sm = max(mx_xor_sm, mx_xor_sm ^ B[b]);
  cout << mx_xor_sm << '\n';
  return 0;
}