#include "bits/stdc++.h"
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
constexpr int sz = 2e5 + 5;
constexpr int mod = 1e9 + 7;
constexpr int inf = 1e18 + 7;
constexpr int N = 1e5 + 5;
 
struct Line{
  int k, b;
  int comp(int x) const {
    return k * x + b;
  }
} tree[(N + 5) << 2];
 
bool has_line[(N + 5) << 2];
 
void init(){
  for(int i = 0; i < ((N + 5) << 2); ++i){
    has_line[i] = false;
  }
}
 
void update_line(int node, int l, int r, Line new_line){
  if(!has_line[node]){
    tree[node] = new_line;
    has_line[node] = true;
    return;
  }
  int mid = l + ((r - l) >> 1);
  bool lb = (new_line.comp(l) > tree[node].comp(l));
  bool mb = (new_line.comp(mid) > tree[node].comp(mid));
 
  if(mb) swap(tree[node], new_line);
 
  if(r == l) return;
 
  if(lb ^ mb){
    update_line(node << 1, l, mid, new_line);
  }else{
    update_line(node << 1 | 1, mid + 1, r, new_line);
  }
  return;
}
 
void update_segment(int node, int l, int r, int L, int R, const Line &line){
  if(l > R or r < L) return;
  if(l >= L and r <= R){
    update_line(node, l, r, line);
    return;
  }
  int mid = l + ((r - l) >> 1);
  update_segment(node << 1, l, mid, L, R, line), update_segment(node << 1 | 1, mid + 1, r, L, R, line);
}
 
 
int get_ans(int node, int l, int r, int x){
  int res = -inf;
  if(has_line[node]) res = max(res, tree[node].comp(x));
  if(l == r) return res;
  int mid = l + ((r - l) >> 1);
  if(x <= mid){
    res = max(res, get_ans(node << 1, l, mid, x));
  }else{
    res = max(res, get_ans(node << 1 | 1, mid + 1, r, x));
  }
  return res;
}
 
int n, type, a, b, x;
 
void solve(){
  cin >> n;
  init();
  for(int i = 0, l, r; i < n; ++i){
    cin >> type;
    if(type ^ 1){
      cin >> x;
      int res = get_ans(1, 0, N, x);
      if(res == -inf) cout << "NO" << '\n';
      else cout << res << '\n';
    }else{
      cin >> a >> b >> l >> r;
      update_segment(1, 0, N, l, r, {a, b});
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