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
 
int n, Q, a[sz], tree[sz << 2], lazy[sz << 2], lazy_set[sz << 2];
 
inline void build(int l, int r, int node){
    if(l == r){
        tree[node] = a[l];
        return;
    }
    int mid = ((l + r) >> 1);
    build(l, mid, node << 1), build(mid + 1, r, node << 1 | 1);
    tree[node] = tree[node << 1] + tree[node << 1 | 1];
    return;
}
 
inline void relax(int l, int r, int node){
    if(lazy[node] || lazy_set[node]){
        int mid = ((l + r) >> 1);
        if(lazy_set[node]){
            tree[node << 1] = lazy_set[node] * (mid - l + 1);
            tree[node << 1 | 1] = lazy_set[node] * (r - mid);
            lazy_set[node << 1] = lazy_set[node << 1 | 1] = lazy_set[node];
            lazy[node << 1 | 1] = lazy[node << 1] = lazy_set[node] = 0ll;
        }
        tree[node << 1] += lazy[node] * (mid - l + 1);
        tree[node << 1 | 1] += lazy[node] * (r - mid);
        lazy[node << 1] += lazy[node];
        lazy[node << 1 | 1] += lazy[node];
        lazy[node] = 0ll;
    }
    return;
}
 
inline void update(int l, int r, int node, int L, int R, int x){
    if(l >= L && r <= R){
        tree[node] += (r - l + 1) * x;
        lazy[node] += x;
        return;
    }
    relax(l, r, node);
    int mid = ((l + r) >> 1);
    if(mid >= L) update(l, mid, node << 1, L, R, x);
    if(mid < R) update(mid + 1, r, node << 1 | 1, L, R, x);
    tree[node] = tree[node << 1] + tree[node << 1 | 1];
    return;
}
 
inline void update_set(int l, int r, int node, int L, int R, int x){
    if(l >= L && r <= R){
        lazy_set[node] = x;
        tree[node] = (r - l + 1) * x;
        lazy[node] = 0ll;
        return;
    }
    relax(l, r, node);
    int mid = ((l + r) >> 1);
    if(mid >= L) update_set(l, mid, node << 1, L, R, x);
    if(mid < R) update_set(mid + 1, r, node << 1 | 1, L, R, x);
    tree[node] = tree[node << 1] + tree[node << 1 | 1];
    return;
}
 
inline int get_ans(int l, int r, int node, int L, int R){
    relax(l, r, node);
    if(l > R || r < L || r < l) return 0ll;
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
    int type, l, r, x;
    while(Q--){
        in(type), in(l), in(r);
        if(type == 1){
            in(x);
            update(1, n, 1, l, r, x);
        }else if(type == 2){
            in(x);
            update_set(1, n, 1, l, r, x);
        }else{
            printf("%lld\n", get_ans(1, n, 1, l, r));
        }
    }
}