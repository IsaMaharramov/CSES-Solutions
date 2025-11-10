// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include "bits/stdc++.h"
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
constexpr int sz = 1e5 + 5;
constexpr int mod = 1e9 + 7;
 
struct Event{
    int x, y1, y2, type;  // 1 = start  -1 = end
};
 
struct SegTree{
    vector<int> cnt, y_vals, len;
    int n;
    
    SegTree(vector<int> &ycs){
        n = (int)ycs.size() - 1;
        cnt.resize(n << 2), len.resize(n << 2);
        y_vals = ycs;
    }
    
    void update(int node, int l, int r, int ql, int qr, int val){
        if(qr < l || ql > r) return;
        if(ql <= l && r <= qr){
            cnt[node] += val;
        }else{
            int mid = l + ((r - l) >> 1);
            update(node << 1, l, mid, ql, qr, val), update(node << 1 | 1, mid + 1, r, ql, qr, val);
        }
        if (cnt[node] > 0) len[node] = y_vals[r+1] - y_vals[l];
        else len[node] = ((l ^ r) ? len[node << 1] + len[node << 1 | 1] : 0ll);  // y-length
        return;
    }
    
    void update(int l, int r, int val){ if(l <= r) update(1, 0, n - 1, l, r, val); }
    
    inline int query(){ return len[1]; }
};
 
int n;
vector<Event> e;
set<int> sty;
 
void solve(){
    cin >> n;
    for(int i = 0, x1, x2, y1, y2; i < n; ++i) {
        cin >> x1 >> y1 >> x2 >> y2;
        e.emplace_back(Event{x1, y1, y2, 1}), e.emplace_back(Event{x2, y1, y2, -1});
        sty.insert(y1), sty.insert(y2);
    }
    vector<int> ycs(all(sty));
    unordered_map<int, int> ymp;
    for(int i = 0; i < (int)ycs.size(); ++i) ymp[ycs[i]] = i;
    sort(e.begin(), e.end(), [&](const Event& a, const Event& b){ return a.x < b.x; });
    SegTree st(ycs);
    int ans(0), px = e[0].x;
    for(const Event &j : e){
        if(j.x != px){
            ans += (j.x - px) * st.query(); // w * h
            px = j.x;
        }
        st.update(ymp[j.y1], ymp[j.y2] - 1, j.type);
    }
    return cout << ans << '\n', void(0);
}
 
signed main(){
  cout.tie(0)->sync_with_stdio(0);
  cin.tie(0)->sync_with_stdio(0);
  int T{1};
  //cin >> T;
  while(T--) solve();
  return 0;
}