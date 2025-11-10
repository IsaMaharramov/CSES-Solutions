#include "bits/stdc++.h"
using namespace std;
 
#define int long long
 
constexpr int sz = 2e5 + 5;
constexpr int inf = 1e9 + 7;
 
int n, st[sz << 4], dp[sz << 2];
 
struct em{
  int a, b, p;
} q[sz];
 
inline void update(int l, int r, int in, int x, int val){
  if(x > r || x < l) return;
  if(l == r){
    st[in] = val;
    return;
  }
  int mid = l + ((r - l) >> 1);
  update(l, mid, in << 1, x, val), update(mid + 1, r, in << 1 | 1, x, val);
  st[in] = max(st[in << 1], st[in << 1 | 1]);
  return;
}
 
inline int get_ans(int l, int r, int in, int L, int R){
  if(l > r || l > R || r < L) return 0ll;
  if(l >= L && r <= R) return st[in];
  int mid = l + ((r - l) >> 1);
  return max(get_ans(l, mid, in << 1, L, R), get_ans(mid + 1, r, in << 1 | 1, L, R));
}
 
int tot, ans;
map<int, int> mp;
 
signed main(){
  ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
  cin >> n;
  for(register int i = 1; i <= n; ++i){
    cin >> q[i].a >> q[i].b >> q[i].p;
    mp[q[i].a], mp[q[i].b];
  }
 
  for(auto &to : mp) to.second = ++tot;
 
  for(register int i = 1; i <= n; ++i){
    q[i].a = mp[q[i].a], q[i].b = mp[q[i].b];
  }
 
  mp.clear();
 
 
  sort(q+1, q+n+1, [&](const em &x, const em &y){ return ((x.b ^ y.b) ? (x.b < y.b) : (x.a < y.a)); });
 
 
  for(register int i = 1; i <= n; ++i){
    int x = get_ans(1, (n << 1 | 1), 1, 1, q[i].a - 1);
    dp[q[i].b] = max(dp[q[i].b], x + q[i].p);
    update(1, (n << 1 | 1), 1, q[i].b, dp[q[i].b]);
    ans = max(ans, dp[q[i].b]);
  }
 
  cout << ans << '\n';
 
}