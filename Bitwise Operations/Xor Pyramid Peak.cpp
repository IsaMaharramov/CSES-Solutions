#include "bits/stdc++.h"
using namespace std;
 
constexpr int sz = 2e5 + 5;
 
#define int long long
 
signed main(){
  cout.tie(0)->sync_with_stdio(0);
  cin.tie(0)->sync_with_stdio(0);
  int N = (cin >> N, N);
  vector<int> A(N);
  for(int &j : A) cin >> j;
  int ans{0ll};
  for(int i = 0; i < N; ++i){
    if((i & (N - 1)) == i) ans ^= A[i];
  }
  return cout << ans << '\n', 0;
}
