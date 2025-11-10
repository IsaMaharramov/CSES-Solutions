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
 
 
int n, m;
vector<Line> tree;
vector<bool> has_line;
 
void init(){
  tree.resize((m + 10) << 2);
  has_line.assign((m + 10) << 2, false);
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
 
  if(r == l) return;
 
  if(lb ^ mb){
    add_line(node << 1, l, mid, new_line);
  }else{
    add_line(node << 1 | 1, mid + 1, r, new_line);
  }
  return;
}
 
void update_segmet(int node, int l, int r, int L, int R, const Line &line){
  if(l > R or r < L) return;
  if(l >= L and r <= R) return add_line(node, l, r, line), void(0);
  int mid = l + ((r - l) >> 1);
  update_segmet(node << 1, l, mid, L, R, line), update_segmet(node << 1 | 1, mid + 1, r, L, R, line);
  return;
}
 
int get_ans(int node, int l, int r, int x){
  int res = -inf;
  if(has_line[node]) res = max(res, tree[node].comp(x));
  if(r == l) return res;
  int mid = l + ((r - l) >> 1);
  if(x <= mid){
    res = max(res, get_ans(node << 1, l, mid, x));
  }else{
    res = max(res, get_ans(node << 1 | 1, mid + 1, r, x));
  }
  return res;
}
 
void solve(){
  cin >> n >> m;
  init();
  for(int i = 0, x1, x2, y_1, y_2; i < n; ++i){
    cin >> x1 >> y_1 >> x2 >> y_2;
    int k = (y_2 - y_1) / (x2 - x1);
    int b = y_1 - k * x1;
    update_segmet(1, 0, m, x1, x2, {k, b});
  }
 
  for(int x = 0; x <= m; ++x){
    int res = get_ans(1, 0, m, x);
    cout << (res == -inf ? -1 : res) << " \n"[x == m];
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