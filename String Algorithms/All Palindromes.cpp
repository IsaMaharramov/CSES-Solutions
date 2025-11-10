#include "bits/stdc++.h"
using namespace std;
// #define int long long
constexpr int sz = 2e5 + 5;
constexpr int mod = 1e9 + 7;
 
struct Node{
  int len, lnk;
  map<char, int> nxt;
};
 
int n;
string s;
 
void solve(){
  cin >> s;
  n = (int)s.size();
  vector<Node> tree(n + 10);
  vector<int> ans(n);
  int suff = 2, cnt = 2;
  tree[1].len = -1;
  tree[1].lnk = 1;
  tree[2].len = 0;
  tree[2].lnk = 1;
 
  for(int i = 0, cur; i < n; ++i){
    char ch = s[i];
    cur = suff;
    while(true){
      int cur_ln = tree[cur].len;
      if(i - cur_ln - 1 >= 0 and s[i - cur_ln - 1] == ch) break;
      cur = tree[cur].lnk;
    }
    if(tree[cur].nxt.count(ch)){
      suff = tree[cur].nxt[ch];
      ans[i] = tree[suff].len;
      continue;
    }
 
    suff = ++cnt;
    tree[cur].nxt[ch] = cnt;
    tree[cnt].len = tree[cur].len + 2;
 
    if(tree[cnt].len == 1){
      tree[cnt].lnk = 2;
    }else{
      while(true){
        cur = tree[cur].lnk;
        int cur_ln = tree[cur].len;
        if(i - cur_ln - 1 >= 0 and s[i - cur_ln - 1] == ch){
          tree[cnt].lnk = tree[cur].nxt[ch];
          break;
        }
      }
    }
    ans[i] = tree[cnt].len;
  }
 
  for(int i = 0; i < n; ++i) cout << ans[i] << " \n"[i==n-1];
 
}
 
signed main(){
  cout.tie(0)->sync_with_stdio(0);
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  //cin >> t;
  while(t--) solve();
  return 0;
}