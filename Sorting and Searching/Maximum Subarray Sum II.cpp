#include "bits/stdc++.h"
using namespace std;
 
#define intt long long
 
constexpr int sz = (int)2e5 + 5;
constexpr intt inf = (intt)1e18 + 7;
 
int n, a, b, c[sz];
intt pref[sz], st[sz << 2], ans(-inf);
 
inline void build(int l, int r, int in){
    if(l == r){
        st[in] = pref[l];
        return;
    }
    int mid = ((l + r) >> 1);
    build(l, mid, in << 1), build(mid + 1, r, in << 1 | 1);
    st[in] = min(st[in << 1], st[in << 1 | 1]);
    return;
}
 
inline intt get_ans(int l, int r, int in, int L, int R){
    if(l > r || l > R || r < L) return inf;
    if(l >= L && r <= R) return st[in];
    int mid = ((l + r) >> 1);
    return min(get_ans(l, mid, in << 1, L, R), get_ans(mid + 1, r, in << 1| 1, L, R));
}
 
signed main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> a >> b;
    for(register int i = 1; i <= n; ++i){
        cin >> c[i];
        pref[i] = pref[i - 1] + c[i];
    }
    build(1, n, 1);
    ans = pref[a];
    for(register int r = a + 1; r <= n; ++r){
    	if(r <= b) ans = max(ans, pref[r]);
        ans = max(ans, pref[r] - get_ans(1, n, 1, max(1, r - b), r - a));
    }
    cout << ans << '\n';
}