#include<iostream>
#include<random>
#include<chrono>
#include<vector>
#include<algorithm>
#define SPEED ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define oo 1000000001
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define mpr make_pair
#define ll long long
 
using namespace std;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int sz = 2e5 + 5;
 
int n, m;
 
int a[sz];
 
struct My_tree{
   ll pref, suff, sum, mxsum;
}tree[sz << 2];
 
ll max3(ll a1, ll a2, ll a3){
    return max(max(a1, a2), a3);
}
 
ll max4(ll a1, ll a2, ll a3, ll a4){
    return max(a1, max3(a2, a3, a4));
}
 
void push_up(int node){
    tree[node].sum = tree[node << 1].sum + tree[node << 1 | 1].sum;
    tree[node].mxsum = max4(tree[node << 1].mxsum, tree[node << 1 | 1].mxsum, tree[node << 1].pref + tree[node << 1 | 1].suff, 0ll);
    tree[node].pref = max3(tree[node << 1 | 1].pref, tree[node << 1].pref + tree[node << 1 | 1].sum, 0ll);
    tree[node].suff = max3(tree[node << 1].suff, tree[node << 1].sum + tree[node << 1 | 1].suff, 0ll);
    return;
}
 
 
void build(int l, int r, int node){
    if(l == r){
        tree[node].suff = tree[node].pref = tree[node].mxsum = max(0, a[l]);
        tree[node].sum = a[l];
        return;
    }
    int mid = l + ((r - l) >> 1);
    build(l, mid, node << 1);
    build(mid + 1, r, node << 1 | 1);
    push_up(node);
    return;
}
 
void update(int l, int r, int node, int x, int val){
    if(x < l || x > r) return;
    if(l == r){
        tree[node].mxsum = tree[node].pref = tree[node].suff = max(0, val);
        tree[node].sum = val;
        return;
    }
    int mid = l + ((r - l) >> 1);
    update(l, mid, node << 1, x, val);
    update(mid + 1, r, node << 1 | 1, x, val);
    push_up(node);
    return;
}
 
signed main(){
    SPEED;
    cin >> n >> m;
    for(register int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    build(1, n, 1);
    int k, x;
    while(m--){
        cin >> k >> x;
        update(1, n, 1, k, x);
        cout << tree[1].mxsum << '\n';
    }
    return 0;
}