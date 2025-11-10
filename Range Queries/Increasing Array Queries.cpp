#include "bits/stdc++.h"
using namespace std;
 
#define int long long
 
constexpr int sz = 2e5 + 5;
constexpr int inf = 1e9 + 7;
 
int n, q, x[sz], suff[sz], preff[sz];
 
struct Node{
    int mx, ans;
} tree[sz << 2];
 
Node operator+(Node i, Node j){
    return Node{max(i.mx, j.mx), (i.mx >= j.mx ? i.ans : j.ans)};
}
 
void build(int l, int r, int node){
    if(l == r) return tree[node] = {x[l], l}, void(0);
    int mid = l + ((r - l) >> 1);
    build(l, mid, node << 1), build(mid + 1, r, node << 1 | 1);
    tree[node] = tree[node << 1] + tree[node << 1 | 1];
}
 
Node Zro{-inf, 0ll};
 
inline Node get_ans(int l, int r, int node, int L, int R){
    if(l > r or l > R or r < L) return Zro;
    if(l >= L and r <= R) return tree[node];
    int mid = l + ((r - l) >> 1);
    return get_ans(l, mid, node << 1, L, R) + get_ans(mid + 1, r, node << 1 | 1, L, R);
}
 
/*
 
 
[a, b]
 
mxi = index of local[a, b] max 
 
tot = (suff[a] - suff[mxi]) + (b - mxi + 1) * x[mxi]
 
 
*/
 
 
void solve(){
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        preff[i] = (cin >> x[i], preff[i-1] + x[i]);
    }
 
    stack<int> st;
 
    for(int i = n; i; --i){
        while(!st.empty() and x[st.top()] <= x[i]){
            st.pop();
        }
        if(st.empty()){
            suff[i] = x[i] * (n - i);
        }else{
            suff[i] = suff[st.top()] + x[i] * (st.top() - i); 
        }
        st.push(i);
    }
 
    build(1, n, 1);
 
    int a, b, tot;
    while(q--){
        cin >> a >> b;
        int mxi = get_ans(1, n, 1, a, b).ans;
        tot = suff[a] - suff[mxi] + (b - mxi + 1) * x[mxi];
        cout << tot - (preff[b] - preff[a - 1]) << '\n';
    }
}
 
signed main(){
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0)->sync_with_stdio(0);
    int TT{1};
    //cin >> TT;
    while(TT--) solve();
    return 0;
}