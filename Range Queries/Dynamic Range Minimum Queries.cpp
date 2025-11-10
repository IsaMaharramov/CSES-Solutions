#include<iostream>
using namespace std;
using ll = long long;
const int sz = 2e5 + 5;
const int inf = 1e9 + 9;
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
int tree[sz << 2];
int a[sz];
void build(int l, int r, int node){
    if(l == r){
        tree[node] = a[l];
        return;
    }
    int mid = l + ((r - l) >> 1);
    build(l, mid, node << 1);
    build(mid + 1, r, node << 1 | 1);
    tree[node] = min(tree[node << 1], tree[node << 1 | 1]);
    return;
}
void update(int l, int r, int x, int val, int node){
    if(x > r || x < l) return;
    if(l == r){
        tree[node] = val;
        return;
    }
    int mid = l + ((r - l) >> 1);
    update(l, mid, x, val, node << 1);
    update(mid + 1, r, x, val, node << 1 | 1);
    tree[node] = min(tree[node << 1], tree[node << 1 | 1]);
    return;
}
ll get_answer(int l, int r, int L, int R, int node){
    if(l > R || r < L) return inf;
    if(l >= L && r <= R) return tree[node];
    int mid = l + ((r - l) >> 1);
    return min(get_answer(l, mid, L, R, node << 1), get_answer(mid + 1, r, L, R, node << 1 | 1));
}
int main(){
    cin.tie()->sync_with_stdio();
    int n, q, l, r, op;
    readInt(n); readInt(q);
    for(register int i = 1; i <= n; ++i) readInt(a[i]);
    build(1, n, 1);
    while(q--){
        readInt(op); readInt(l); readInt(r);
        if(op == 2) cout << get_answer(1, n, l, r, 1) << '\n';
        else update(1, n, l, r, 1);
    }
    exit(0);
}