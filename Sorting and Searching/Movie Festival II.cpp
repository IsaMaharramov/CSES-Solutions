#include "bits/stdc++.h"
using namespace std;
 
constexpr int sz = 2e5 + 5;
 
struct modr{
    int a, b;
} c[sz];
 
int n, k, ans;
 
multiset<int> st;
 
signed main(){
    ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    cin >> n >> k;
    for(register int i = 1; i <= n; ++i){
        cin >> c[i].a >> c[i].b;
    }
    sort(c+1, c+n+1, [&](const modr &u, const modr &v){
        return ((u.b ^ v.b) ? (u.b < v.b) : (u.a < v.a));
    });
    for(register int i = 1; i <= k; ++i){
        st.insert(1);
    }
 
    for(register int i = 1; i <= n; ++i){
 
        auto it = st.upper_bound(c[i].a);
 
        if(it == st.begin()) continue;
 
        --it;
 
        ++ans;
 
        st.erase(it);
 
        st.insert(c[i].b);
 
    }
 
    cout << ans << '\n';
 
}