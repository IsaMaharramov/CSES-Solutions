#include "bits/stdc++.h"
using namespace std;
constexpr int sz = 2e5 + 5;
constexpr int mod = 1e9 + 7;
#define int long long
void solve(){
    int n = (cin >> n, n);
    bool flag{false};
    for(int i = 1, xi; i <= n; ++i){
        cin >> xi;
        flag |= (xi & 1);
    }
    cout << (flag ? "first" : "second") << '\n';
} 
signed main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T{1};
    cin >> T;
    while(T--) solve();
    return 0;
}