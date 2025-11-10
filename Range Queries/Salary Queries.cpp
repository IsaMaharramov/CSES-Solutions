#include "bits/stdc++.h"
using namespace std;
 
constexpr int sz = (int)2e5 + 5;
int n, Q, p[sz], tree[sz << 2], tot;
 
inline void update(int pos, int val){
    while(pos < tot){
        tree[pos] += val;
        pos += (pos & (-pos));
    }
    return;
}
 
inline int get_ans(int l, int r){
    if(l > r) return 0;
    if(l != 1) return get_ans(1, r) - get_ans(1, l - 1);
    int res(0);
    while(r > 0){
        res += tree[r];
        r -= (r & (-r));
    }
    return res;
}
 
#define eb emplace_back
 
vector<int> v;
int q[3][sz];
 
signed main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> Q;
    for(register int i = 1; i <= n; ++i) cin >> p[i], v.eb(p[i]);
    char ch;
    for(register int i = 1, a, b; i <= Q; ++i) cin >> ch >> a >> b, q[0][i] = a, q[1][i] = b, q[2][i] = (ch == '?'), v.eb(a), v.eb(b);
    sort(v.begin(), v.end());
    auto it = unique(v.begin(), v.end());
    v.erase(it, v.end());
    function<int(int)> f = [&](int x)->int{ return int(lower_bound(v.begin(), v.end(), x) - v.begin() + 1); };
    tot = (int)v.size() + 10;
    for(register int i = 1; i <= Q; ++i){
        q[1][i] = f(q[1][i]);
        if(q[2][i]) q[0][i] = f(q[0][i]);
    }
    ++tot;
    for(register int i = 1; i <= n; ++i) p[i] = f(p[i]), update(p[i], 1);
    for(register int i = 1; i <= Q; ++i){
        int a = q[0][i], b = q[1][i];
        if(q[2][i]) cout << get_ans(a, b) << '\n';
        else update(p[a], -1), p[a] = b, update(p[a], 1);
    }
}