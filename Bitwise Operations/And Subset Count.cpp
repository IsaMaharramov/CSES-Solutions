#include "bits/stdc++.h"
using namespace std;
#define int long long
 
constexpr int sz = 2e5 + 5;
constexpr int mod = 1e9 + 7;
 
int qpow(int a, int b){
  int res{1};
  a %= mod;
  while(b>0){
    if(b & 1) res = res * a % mod;
    a = (b >>= 1, a * a % mod);
  }
  return res;
}
 
signed main(){
  cout.tie(0)->sync_with_stdio(0);
  cin.tie(0)->sync_with_stdio(0);
  int N = (cin >> N, N);
  vector<int> A(N);
  for(int &j : A) cin >> j;
  const int K = 18;
  const int M = (1 << K);
  vector<int> C(M, 0);
  for(int &j : A) C[j]++;
  vector<int> B = vector<int>(C.begin(), C.end());
  for(int i = 0; i < K; ++i){
    for(int mask = M - 1; mask >= 0; --mask){
      if((1 << i) & mask) continue;
      B[mask] += B[mask ^ (1 << i)];
    }
  }
 
  vector<int> NE(M); // superset
  for(int i = 0; i < M; ++i){
    NE[i] = (qpow(2, B[i]) - 1 + mod) % mod;
  }
  vector<int> E = NE;
  for(int i = 0; i < K; ++i){
    for(int mask = M - 1; mask >= 0; --mask){
      if((1 << i) & mask) continue;
      E[mask] = (E[mask] - E[mask ^ (1 << i)] + mod) % mod;
    }
  }
  for(int i = 0; i <= N; ++i) cout << E[i] << ' ';
  return 0;
}
