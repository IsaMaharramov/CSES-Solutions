/// https://cp-algorithms.com/game_theory/sprague-grundy-nim.html
#include "bits/stdc++.h"
using namespace std;
#define int long long
#define eb emplace_back
constexpr int sz = 1e6 + 6;
int n, dp[1<<11];
set<int> st;
int MEX(vector<int>& v){
    st.clear();
    for(const long long &j : v) st.insert(j);
    for(int i = 0; i < sz; ++i) if(st.count(i) == 0) return i;
}
void precomp(){
    dp[0] = dp[1] = dp[2] = 0;
    for(int i = 3; i < 2000; ++i){
        vector<int> v;
        for(int j = 1; (j << 1) < i; ++j){
            v.eb(dp[j] ^ dp[i - j]);
        }
        dp[i] = MEX(v);
    }
}
array<string, 2> ans = {"second", "first"};
void solve(){
    cin >> n;
    if(n >= 2000) return cout << "first" << '\n', void(0);
    cout << ans[(bool)dp[n]] << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false), cout.tie(0), cin.tie(0);
    int T{1};
    cin >> T;
    precomp();
    while(T--) solve();
    return 0;
}