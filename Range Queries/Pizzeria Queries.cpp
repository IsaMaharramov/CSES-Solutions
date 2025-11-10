#include<iostream>
#include<vector>
#include<random>
#include<chrono>
#include<algorithm>
#include<set>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define SPEED ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define oo 1000000001
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define f first
#define s second
#define pii pair<int, int>
#define eb emplace_back
#define ll long long
#define ull unsigned long long
#define left lefttt
#define right righttt
 
//using namespace __gnu_pbds;
//template<class T> using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
using namespace std;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int sz = 2e5 + 5;
 
int n, q;
 
int p[sz];
 
struct seg{
    int left, right;
}tree[sz << 2];
 
inline void push_up(int in){
    tree[in].left = min(tree[in << 1].left, tree[in << 1 | 1].left);
    tree[in].right = min(tree[in << 1].right, tree[in << 1 | 1].right);
    return;
}
 
inline void build(int l, int r, int in){
    if(l == r){
        tree[in].left = p[l] - l;
        tree[in].right = p[l] + l;
        return;
    }
    int mid = l + ((r - l) >> 1);
    build(l, mid, in << 1);
    build(mid + 1, r, in << 1 | 1);
    push_up(in);
    return;
}
 
inline void update(int l, int r, int in, int x, int val){
    if(x > r || x < l) return;
    if(l == r){
        tree[in].left = val - l;
        tree[in].right = val + l;
        return;
    }
    int mid = l + ((r - l) >> 1);
    update(l, mid, in << 1, x, val);
    update(mid + 1, r, in << 1 | 1, x, val);
    push_up(in);
    return;
}
 
int get_ansl(int l, int r, int in, int ql, int qr){
    if(qr < l || ql > r) return oo;
    if(l >= ql && r <= qr) return tree[in].left;
    int mid = l + ((r - l) >> 1);
    return min(get_ansl(l, mid, in << 1, ql, qr), get_ansl(mid + 1, r, in << 1 | 1, ql, qr));
}
 
int get_ansr(int l, int r, int in, int ql, int qr){
    if(qr < l || ql > r) return oo;
    if(l >= ql && r <= qr) return tree[in].right;
    int mid = l + ((r - l) >> 1);
    return min(get_ansr(l, mid, in << 1, ql, qr), get_ansr(mid + 1, r, in << 1 | 1, ql, qr));
}
 
 
signed main(){
    SPEED;
    cin >> n >> q;
    for(register int i = 1; i <= n; ++i){
        cin >> p[i];
    }
    build(1, n, 1);
    int type, k, x;
    while(q--){
        cin >> type >> k;
        if(type == 1){
            cin >> x;
            update(1, n, 1, k, x);
        }else{
            cout << min(get_ansl(1, n, 1, 1, k) + k, get_ansr(1, n, 1, k, n) - k) << '\n';
        }
    }
    return 0;
}