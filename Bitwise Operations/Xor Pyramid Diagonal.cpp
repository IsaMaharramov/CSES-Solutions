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
  for(int i = 0; i <= 18; ++i){
    for(int j = 0; j < N; ++j){
      if((1 << i) & j) A[j] ^= A[j ^ (1 << i)];
    }
  }
  for(int &j : A) cout << j << ' ';
  return 0;
}