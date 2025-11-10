#include "bits/stdc++.h"
using namespace std;
 
template<class T>void in(T &x) {
    x = 0; bool f = 0; char c = getchar();
    while (c < '0' || c > '9') {if (c == '-') f = 1; c = getchar();}
    while ('0' <= c && c <= '9') {x = (x << 3) + (x << 1) + (c ^ 48); c = getchar();}
    if (f) x = -x;
}
 
#define int long long
 
constexpr int sz = (int)2e5 + 5;
constexpr int inf = (int)1e17 + 5;
 
int n, m, h[sz], tree[sz << 2];
 
inline void build(int l, int r, int node){
    if(l == r){
        tree[node] = h[l];
        return;
    }
    int mid = ((l + r) >> 1);
    build(l, mid, node << 1), build(mid + 1, r, node << 1 | 1);
    tree[node] = max(tree[node << 1], tree[node << 1 | 1]);
    return;
}
 
inline void update(int l, int r, int node, int x, int val){
    if(l > r || x > r || l > x) return;
    if(l == r){
        tree[node] -= val;
        return;
    }
    int mid = ((l + r) >> 1);
    update(l, mid, node << 1, x, val), update(mid + 1, r, node << 1 | 1, x, val);
    tree[node] = max(tree[node << 1], tree[node << 1 | 1]);
    return;
}
 
inline int get_ans(int l, int r, int node, int L, int R){
    if(l > r || l > R || r < L) return -inf;
    if(l >= L && r <= R) return tree[node];
    int mid = ((l + r) >> 1);
    return max(get_ans(l, mid, node << 1, L, R), get_ans(mid + 1, r, node << 1 | 1, L, R));
}
 
signed main(){
    cout.tie(0);
    in(n), in(m);
    for(register int i = 1; i <= n; ++i){
        in(h[i]);
    }
    build(1, n, 1);
    for(register int i = 1, x; i <= m; ++i){
        in(x);
        int l = 1, r = n, mid, best(0);
        while(l <= r){
            mid = l + ((r - l) >> 1);
            if(get_ans(1, n, 1, 1, mid) >= x){
                best = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        cout << best << " \n"[i==m];
        update(1, n, 1, best, x);
    }
}