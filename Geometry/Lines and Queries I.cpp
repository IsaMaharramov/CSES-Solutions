#include "bits/stdc++.h"
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
constexpr int sz = 1e5 + 5;
constexpr int mod = 1e9 + 7;
constexpr int inf = 1e18 + 7;
 
struct Line{
  int k, b;
  int comp(int x) const {
    return k * x + b;
  }
};
 
vector<Line> tree;
vector<bool> has_line;
 
void init(int n){
  tree.resize(n << 2);
  has_line.assign(n << 2, false);
  return;
}
 
void add_line(int node, int l, int r, Line new_line){
  if(!has_line[node]){
    tree[node] = new_line;
    has_line[node] = true;
    return;
  }
  int mid = l + ((r - l) >> 1);
  bool lb = (new_line.comp(l) > tree[node].comp(l));
  bool mb = (new_line.comp(mid) > tree[node].comp(mid));
 
  if(mb) swap(tree[node], new_line);
 
  if(r - l == 1) return;
 
  if(lb ^ mb){
    add_line(node << 1, l, mid, new_line);
  }else{
    add_line(node << 1 | 1, mid, r, new_line);
  }
  return;
}
 
int get_ans(int node, int l, int r, int x){
  if(!has_line[node]) return -inf;
  int res = tree[node].comp(x);
  if(r - l == 1) return res;
  int mid = l + ((r - l) >> 1);
  if(x < mid){
    res = max(res, get_ans(node << 1, l, mid, x));
  }else{
    res = max(res, get_ans(node << 1 | 1, mid + 1, r, x));
  }
  return res;
}
 
int n, type, a, b, x;
 
void solve(){
  cin >> n;
  init(n + 10);
  for(int i = 0; i < n; ++i){
    cin >> type;
    if(type ^ 1){
      cin >> x;
      cout << get_ans(1, 0, n + 1, x) << '\n';
    }else{
      cin >> a >> b;
      add_line(1, 0, n + 1, {a, b});
    }
  }
}
signed main(){
  cout.tie(0)->sync_with_stdio(0);
  cin.tie(0)->sync_with_stdio(0);
  int T{1};
  //cin >> T;
  while(T--) solve();
  return 0;
}