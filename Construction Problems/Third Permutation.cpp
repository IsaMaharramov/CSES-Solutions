#include "bits/stdc++.h" 
using namespace std;
 
#define int long long
constexpr int inf = 1e18 + 7;
constexpr int mod = 1e9 + 7;
constexpr int sz = 2e5 + 5;
 
 
int n, a[sz], b[sz], ans[sz];
set<int> st;
 
void solve(){
    cin >> n;
 
    for(int i = 1; i <= n; ++i){
        st.insert((cin >> a[i], (i)));
    }
    for(int i = 1; i <= n; ++i){
        cin >> b[i];
    }
    if(n <= 2) return puts("IMPOSSIBLE"), void(0);
    for(int i = 1; i <= n - 3; ++i){
        for(auto j : st){
            if((a[j] ^ i) and (b[j] ^ i)){
                ans[j] = i;
                st.erase(j);
                break;
            }
        }
    }
 
    vector<int> p = {n - 2, n - 1, n};
    loop:
        bool flag = true;
        auto it = st.begin();
        for(int i = 0, j; i < 3; ++i) flag &= (j = *(it++), !(a[j] == p[i] | b[j] == p[i]));
        if(flag){ 
            it = st.begin();
            for(int i = 0; i < 3; ++i) ans[*(it++)] = p[i];
        }
    if(next_permutation(p.begin(), p.end())) goto loop;
 
    
 
    for(int i = 1; i <= n; ++i){
        cout << ans[i] << ' ';
    }
 
}
 
signed main(){
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}