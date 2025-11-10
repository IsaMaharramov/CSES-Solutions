#include "bits/stdc++.h"
using namespace std;
 
constexpr int sz = 2e5 + 5;
 
#define int long long
 
signed main(){
  cout.tie(0)->sync_with_stdio(0);
  cin.tie(0)->sync_with_stdio(0);
  int N, K;
  K = (cin >> N >> K, N - K);
  vector<int> A(N);
  for(int &j : A) cin >> j;
  for(int i = 0; i <= 18; ++i){
    if(!((1 << i) & K)) continue;
    for(int j = 0; j + (1 << i) < N; ++j){
      A[j] ^= A[j + (1 << i)];
    }
  }
  for(int i = 0; i < N - K; ++i){
    cout << A[i] << ' ';
  }
  return 0;
}