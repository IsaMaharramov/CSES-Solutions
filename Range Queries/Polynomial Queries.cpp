#include "bits/stdc++.h"
using namespace std;
 
template<class T>void in(T &x) {
    x = 0; bool f = 0; char c = getchar();
    while (c < '0' || c > '9') {if (c == '-') f = 1; c = getchar();}
    while ('0' <= c && c <= '9') {x = (x << 3) + (x << 1) + (c ^ 48); c = getchar();}
    if (f) x = -x;
}
 
#define int long long
 
constexpr int sz = (int)2.8e5 + 5;
 
int n, Q, a[sz], tree[sz << 2];
 
struct tag{
    int cnt, sm;
    tag operator+(const tag &x)const{
        tag res;
        res.sm = sm + x.sm;
        res.cnt = cnt + x.cnt;
        return res;
    }
} lazy[sz << 2];
 
inline void build(int l, int r, int node){
    if(l == r){
        tree[node] = a[l];
        return;
    }
    int mid = ((l + r) >> 1);
    build(l, mid, node << 1), build(mid + 1, r, node << 1 | 1);
    tree[node] = tree[node << 1] + tree[node << 1 | 1];
}
 
inline void relax(int l, int r, int node){
    if(!lazy[node].sm) return;
    lazy[node << 1] = lazy[node << 1] + lazy[node];
    lazy[node << 1 | 1] = lazy[node << 1 | 1] + lazy[node];
    tree[node] += ((lazy[node].cnt * (r * r - l * l + 3 * r - l + 2) / 2) - (r + 1 - l) * lazy[node].sm);
    lazy[node] = tag{0ll, 0ll};
    return;
}
 
inline void update(int l, int r, int node, int L, int R){
    relax(l, r, node);
    if(l > r || l > R || r < L) return;
    if(l >= L && r <= R){
        lazy[node] = tag{1, L};
        relax(l, r, node);
        return;
    }
    int mid = ((l + r) >> 1);
    update(l, mid, node << 1, L, R);
    update(mid + 1, r, node << 1 | 1, L, R);
    tree[node] = tree[node << 1] + tree[node << 1 | 1];
    return;
}
 
inline int get_ans(int l, int r, int node, int L, int R){
    if(l > r) return 0ll;
    relax(l, r, node);
    if(l > R || r < L) return 0ll;
    if(l >= L && r <= R) return tree[node];
    int mid = ((l + r) >> 1);
    return get_ans(l, mid, node << 1, L, R) + get_ans(mid + 1, r, node << 1 | 1, L, R);
}
 
signed main(){
    in(n), in(Q);
    for(register int i = 1; i <= n; ++i){
        in(a[i]);
    }
    build(1, n, 1);
    int type, l, r;
    while(Q--){
        in(type), in(l), in(r);
        if(type == 1){
            update(1, n, 1, l, r);
        }else{
            printf("%lld\n", get_ans(1, n, 1, l, r));
        }
    }
}