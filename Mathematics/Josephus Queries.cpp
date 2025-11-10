#include "bits/stdc++.h"
using namespace std;
#define int long long
constexpr int sz = 2e5 + 5;
int q;
void solve(){
    cin >> q;
    function<int(int, int)> f = [&](int n, int k)->int{
        if(n == 1) return 1;
        return ((k <= (n + 1) >> 1) ? ((k << 1) > n ? (k << 1) % n : (k << 1)) : ((f(n >> 1, k - ((n + 1) >> 1)) << 1) + (n & 1 ? 1 : -1)));
    };
    int n, k;
    while(q--){
        cin >> n >> k;
        cout << f(n, k) << '\n';
    }
}
signed main(){
    ios_base::sync_with_stdio(false), cout.tie(0), cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}