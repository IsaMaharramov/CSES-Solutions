#include<iostream>
#include<vector>
#include<random>
#include<chrono>
#include<algorithm>
#include<map>
#define SPEED ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define oo 1000000001
#define rall(v) (v).rbegin(),(v).rend()
#define all(v) (v).begin(),(v).end()
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define ll long long
#define ull unsigned long long
 
using namespace std;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#define int ll
 
constexpr int sz = 2e5 + 5;
constexpr int inf = 1e9 + 7;
 
struct Node{
    int sm, ans, pref, suff;
} tree[sz << 2];
 
Node operator+(Node i, Node j){
    Node res = {0, 0, 0, 0};
    res.ans = max({0ll, i.ans, j.ans, i.suff + j.pref});
    res.sm = i.sm + j.sm;
    res.pref = max({0ll, i.pref, i.sm + j.pref});
    res.suff = max({0ll, j.suff, i.suff + j.sm});
    return res;
}
 
int x[sz];
 
void build(int node, int l, int r){
    if(l == r)  return tree[node] = Node{x[l], max(0ll, x[l]), max(0ll, x[l]), max(0ll, x[l])}, void(0);
    int mid = l + ((r - l) >> 1);
    build(node << 1, l, mid), build(node << 1 | 1, mid + 1, r);
    return tree[node] = tree[node << 1] + tree[node << 1 | 1], void(0);
}
 
Node Zro = {0ll, 0ll, 0ll, 0ll};
 
Node get_ans(int l, int r, int node, int L, int R){
    if(l > r or l > R or r < L) return Zro;
    if(l >= L and r <= R) return tree[node];
    int mid = l + ((r - l) >> 1);
    return get_ans(l, mid, node << 1, L, R) + get_ans(mid + 1, r, node << 1 | 1, L, R);
}
  
int n, q;
 
void solve(){
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        cin >> x[i];
    }
    build(1, 1, n);
    register int a, b;
    while(q--){
        cin >> a >> b;
        cout << get_ans(1, n, 1, a, b).ans << '\n';
    }
    return;
}
 
signed main(){
  SPEED;
  int TT{1};
  //cin >> TT;
  while(TT--) solve();
  return 0;
}