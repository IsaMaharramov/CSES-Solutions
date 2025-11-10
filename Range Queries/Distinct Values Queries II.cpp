#include "bits/stdc++.h"
using namespace std;
 
#define int long long
 
constexpr int sz = 1e6 + 6;
constexpr int inf = 1e9 + 7;
 
int n, q, x[sz], nextt[sz], prevv[sz], tree[sz << 2];
 
void build(int l, int r, int node){
    if(l == r) return tree[node] = nextt[l], void(0);
    int mid = l + ((r - l) >> 1);
    build(l, mid, node << 1), build(mid + 1, r, node << 1 | 1);
    tree[node] = min(tree[node << 1], tree[node << 1 | 1]);
    return;
}
 
void update(int l, int r, int node, int pos, int val){
    if(l > r or l > pos or r < pos) return;
    if(l == r){
        tree[node] = val;
        return;
    }
    int mid = l + ((r - l) >> 1);
    update(l, mid, node << 1, pos, val), update(mid + 1, r, node << 1 | 1, pos, val);
    tree[node] = min(tree[node << 1], tree[node << 1 | 1]);
}
 
inline int get_ans(int l, int r, int node, int L, int R){
    if(l > r or l > R or r < L) return inf;
    if(l >= L and r <= R) return tree[node];
    int mid = l + ((r - l) >> 1);
    return min(get_ans(l, mid, node << 1, L, R), get_ans(mid + 1, r, node << 1 | 1, L, R));
}
 
map<int, set<int>> mp;
 
void solve(){
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        prevv[i] = 0;
        nextt[i] = n + 1;
        cin >> x[i];
        mp[x[i]].insert(i);
    }
    for(auto &j : mp){
        j.second.insert(n + 1);
        auto it = j.second.begin();
        auto end_it = j.second.end();
        --end_it;
        while(it != end_it){
            int p = *it;
            ++it;
            nextt[p] = *it;
            prevv[*it] = p;
        }
    }
    nextt[n + 1] = n + 1;
    build(1, n, 1);
    register int type, a, b;
    while(q--){
        cin >> type >> a >> b;
        if(type ^ 2){ // a->b     a->c->b
            
            // a -> b
            if(prevv[a]){
                nextt[prevv[a]] = nextt[a];
                update(1, n, 1, prevv[a], nextt[a]);
            }
 
 
            mp[x[a]].erase(a);
                
            x[a] = b;
 
            if(mp[b].empty()) mp[b].insert(n + 1);
 
            mp[b].insert(a);
 
            // a -> c -> b
 
 
            auto it = mp[b].find(a);
 
            if(it != mp[b].begin()){
                --it;
                nextt[*it] = a;
                prevv[a] = *it;
                update(1, n, 1, *it, a);
                ++it;
            }
 
            ++it;
 
            nextt[a] = *it;
            prevv[*it] = a;
            update(1, n, 1, a, *it);
 
                
 
        }else{
            cout << (get_ans(1, n, 1, a, b) <= b ? "NO" : "YES") << '\n';
        }
    }
    return;
}
 
signed main(){
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0)->sync_with_stdio(0);
    int TT{1};
    //cin >> TT;
    while(TT--) solve();
    return 0;
}