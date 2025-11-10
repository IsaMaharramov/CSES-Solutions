#include<iostream>
using namespace std;
using ll = long long;
const int sz = 2e5 + 5;
inline void readInt(int &n){
    char ch;
    int sign = 1;
    while(ch = getchar(), isspace(ch)){//getchar()-->getchar_unlocked()
 
    };
    n = 0;
    if(ch == '-')
        sign = -1;
    else n = ch - '0';
    while(ch = getchar(), isdigit(ch))
        n = (n << 3) + (n << 1) + ch - '0';
    n *= sign;
}
ll tree[sz << 2];
ll lazy[sz << 2];
int a[sz];
void build(int l, int r, int node){
    if(l == r){
        tree[node] = a[l];
        return;
    }
    int mid = l + ((r - l) >> 1);
    build(l, mid, node << 1);
    build(mid + 1, r, node << 1 | 1);
    tree[node] = tree[node << 1] + tree[node << 1 | 1];
    return;
}
void relax(int l, int r, int node){
    if(l != r){
        lazy[node << 1] += lazy[node];
        lazy[node << 1 | 1] += lazy[node];
    }
    tree[node] += lazy[node];
    lazy[node] = 0;
    return;
}
void update(int l, int r, int L, int R, int node, int val){
    if(lazy[node]) relax(l, r, node);
    if(l > R || r < L) return;
    if(l >= L && r <= R){
        lazy[node] = val;
        relax(l, r, node);
    }else{
        int mid = l + ((r - l) >> 1);
        update(l, mid, L, R, node << 1, val);
        update(mid + 1, r, L, R, node << 1 | 1, val);
        tree[node] = tree[node << 1] + tree[node << 1 | 1];
    }
    return;
}
ll get_answer(int l, int r, int L, int R, int node){
    if(l > R || r < L) return 0;
    if(lazy[node]) relax(l, r, node);
    if(l >= L && r <= R) return tree[node];
    int mid = l + ((r - l) >> 1);
    return get_answer(l, mid, L, R, node << 1) + get_answer(mid + 1, r, L, R, node << 1 | 1);
}
int main(){
    cin.tie()->sync_with_stdio();
    int n, q;
    readInt(n); readInt(q);
    for(register int i = 1; i <= n; ++i) readInt(a[i]);
    build(1, n, 1);
    int l, r, k, op;
    while(q--){
        readInt(op);
        if(op == 1){
            readInt(l); readInt(r); readInt(k);
            update(1, n, l, r, 1, k);
        }else{
            readInt(k);
            cout << get_answer(1, n, k, k, 1) << '\n';
        }
    }
    exit(0);
}