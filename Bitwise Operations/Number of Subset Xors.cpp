#include "bits/stdc++.h"
using namespace std;
 
constexpr int sz = 2e5 + 5;
 
#define int long long
 
signed main(){
  cout.tie(0)->sync_with_stdio(0);
  cin.tie(0)->sync_with_stdio(0);
  int K(0), N = (cin >> N, N);
  const int MX_BITS = 30;
  vector<int> B(MX_BITS, 0);
  for(int i = 0, X; i < N; ++i){
    cin >> X;
    for(int b = MX_BITS; b >= 0; --b){
      if(!((1LL << b) & X)) continue;
      if(!B[b]){
        B[b] = (++K, X);
        break;
      }
      X ^= B[b];
    }
  }
  cout << (1LL << K) << '\n';
  return 0;
}