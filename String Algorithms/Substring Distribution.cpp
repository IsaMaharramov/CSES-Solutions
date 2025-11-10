#include "bits/stdc++.h"
using namespace std;
// #define int long long
constexpr int sz = 2e5 + 5;
constexpr int mod = 1e9 + 7;
 
vector<int> build_suff_arr(const string &s){
  int n = (int)s.size();
  vector<int> sa(n), rank(n), tmp(n);
  for(int i = 0; i < n; ++i){
    sa[i] = i;
    rank[i] = s[i];
  }
 
  for(int k = 1; ; k <<= 1){
    auto cmp = [&](int i, int j){
      if(rank[i] ^ rank[j]) return rank[i] < rank[j];
      int ri = ((i + k < n) ? rank[i + k] : -1);
      int rj = ((j + k < n) ? rank[j + k] : -1);
      return ri < rj;
    };
    sort(sa.begin(), sa.end(), cmp);
    tmp[sa[0]] = 0;
    for(int i = 1; i < n; ++i) tmp[sa[i]] = tmp[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
    rank = tmp;
    if(rank[sa[n - 1]] == n - 1) break; 
  }
  return sa;
}
 
vector<int> build_LCP(const string &s, const vector<int> &sa){
  int n{(int)s.size()};
  vector<int> rank(n), lcp(n);
  for(int i = 0; i < n; ++i) rank[sa[i]] = i;
 
  int h = 0;
  for(int i = 0; i < n; ++i){
    if(!rank[i]) continue;
    int j = sa[rank[i] - 1];
    while(i + h < n and j + h < n and s[i + h] == s[j + h]) ++h;
    lcp[rank[i]] = h;
    h -= (h > 0);
  }
  return lcp;
}
 
 
int n;
string s;
 
void solve(){
  cin >> s;
  n = (int)s.size();
 
 
  vector<int> sa = build_suff_arr(s);
  vector<int> lcp = build_LCP(s, sa);
 
  vector<int> ans(n + 10, 0);
 
  for(int i = 0; i < n; ++i){
    ans[(i ? lcp[i] : 0) + 1]++;
    ans[n - sa[i] + 1]--;
  }
 
  for(int i = 1; i <= n; ++i){
    ans[i] += ans[i - 1];
    cout << ans[i] << " \n"[i == n];
  }
 
  return;
}
 
signed main(){
  cout.tie(0)->sync_with_stdio(0);
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  //cin >> t;
  while(t--) solve();
  return 0;
}