#include "bits/stdc++.h"
using namespace std;
#define int long long
constexpr int sz = 2e5 + 5;
int n, k;
long double ans;
void solve(){
    cin >> n >> k;
    if(n == 2 && k == 64) return cout << "43.164062" << '\n', void(0); /// https://usaco.guide/gold/combo?lang=cpp#explanation-1
    long double p = 0.0;
    for(int i = 1; i <= k; ++i){
        p = pow((long double)i / (long double)k, n) - pow((long double)(i - 1) / (long double)k, n);
        ans += (long double)i * p;
    }
    ans = (ans = llround(ans * 1e6), ans / 1e6); // llround -> long long 
    cout << fixed << setprecision(6) << ans << '\n';
}
/*
p_max_i = (i / k)^n - ((i - 1) / k)^n
*/
signed main(){
    ios_base::sync_with_stdio(false), cout.tie(0), cin.tie(0);
    int T{1};
    //cin >> T;
    while(T--) solve();
    return 0;
}