#include "bits/stdc++.h"
#define int long long
using namespace std;
 
constexpr int sz = 2e5 + 5;
 
signed main(){
  cout.tie(0)->sync_with_stdio(0);
  cin.tie(0)->sync_with_stdio(0);
  int N;
  cin >> N;
  const int K = 20;
  const int M = (1 << K);
  const int U = M - 1;
 
  vector<int> A(N), freq(M, 0);
  for(int i = 0; i < N; ++i){
    cin >> A[i];
    freq[A[i]]++;
  }
 
  vector<int> dp_subset = freq;
  for(int i = 0; i < K; ++i){
    for(int mask = 0; mask < M; ++mask){
      if((1 << i) & mask){
        dp_subset[mask] += dp_subset[mask ^ (1 << i)];
      }
    }
  }
 
  vector<int> dp_superset = freq;
  for(int i = 0; i < K; ++i){
    for(int mask = 0; mask < M; ++mask){
      if((1 << i) & mask){
        dp_superset[mask ^ (1 << i)] += dp_superset[mask];
      }
    }
  }
 
  array<int, 3> ans;
 
  for(int x : A){
    ans[0] = (ans[1] = dp_superset[x], dp_subset[x]);
    /// y & x == 0 -> y is a subset of the complement of x
    int complement_mask = U ^ x;
    int disjoint_count = dp_subset[complement_mask];
    ans[2] = N - disjoint_count;
    
    for(int i = 0; i < 3; ++i) cout << ans[i] << " \n"[i == 2];
  }
  return 0;
}