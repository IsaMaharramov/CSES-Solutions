#include "bits/stdc++.h"  /// https://hu.wikipedia.org/wiki/Erd%C5%91s%E2%80%93Szekeres-t%C3%A9tel
using namespace std;
 
constexpr int sz = 1e6 + 6;
 
#define int long long
 
int n, k;
 
void solve(){
    cin >> n >> k;
    if(k * k < n) return cout << "IMPOSSIBLE" << '\n', void(0); // n / k <= k -> n <= k * k
    vector<int> ans(n);
    iota(ans.begin(), ans.end(), 1);
    for(register int i = 0; i < n; i += k) reverse(ans.begin() + i, ans.begin() + min(i + k, n));
    for(int &j : ans) cout << j << ' ';
    cout << '\n';
}
 
signed main(){
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0)->sync_with_stdio(0);
    int TT{1};
    cin >> TT;
    while(TT--) solve();
    return 0;
}