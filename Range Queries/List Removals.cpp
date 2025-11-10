#include "bits/stdc++.h"
using namespace std;
 
constexpr int sz = (int)2e5 + 5;
 
int n, a[sz], tree[sz];
 
inline void update(int pos, int val){
    while(pos <= n){
        tree[pos] += val;
        pos += (pos & (-pos));
    }
    return;
}
 
inline int get_ans(int l, int r){
    assert(l <= r);
    if(l ^ 1) return get_ans(1, r) - get_ans(1, l - 1);
    int res(0);
    while(r > 0){
        res += tree[r];
        r -= (r & (-r));
    }
    return res;
}
 
int fa[sz];
 
signed main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(register int i = 1; i <= n; ++i){
        cin >> a[i];
        update(i, 1);
    }
    for(register int i = 1, x; i <= n; ++i){
        cin >> x;
 
        int l = 1, r = n, mid, best(x);
        while(l <= r){
            mid = l + ((r - l) >> 1);
            if(get_ans(1, mid) >= x){
                best = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        x = best;
        cout << a[x] << ' ';
 
        update(x, -1);
 
    }
}