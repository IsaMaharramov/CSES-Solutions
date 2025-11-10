#include "bits/stdc++.h"
// #include <chrono>
// #include <thread>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define intt long long
#define int intt
#define pb push_back
#define endl '\n'
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<intt,intt>
#define ld long double
#define SPEED ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define vi vector<int>
#define eb emplace_back
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int sz = 2e5+5;
const int inf = 2e9+7;
const intt infl = 1e18;
const ld eps = 1e-9;
const int mod = 1e9 + 7;
int i,j;
void solve(){
    /*
 
    (1 1)^(n-1) -> (F(n) F(n - 1))
    (1 0)       -> (F(n - 1) F(n - 2))
    
    */
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    function<int(int)> f = [&](int n)->int{
        if(n <= 1) return n;
        if(mp[n]) return mp[n];
        int res = 0ll;
        if(~n & 1){
            res = ((2 * f(n / 2 - 1)%mod + f(n / 2)) % mod) * f(n / 2)%mod;
        }else{
            res = (f((n+1) / 2) * f((n+1) / 2)%mod + f((n+1) / 2 - 1) * f((n+1) / 2 - 1)%mod) % mod;
        }
        return mp[n] = res;
    };
    cout << f(n) << '\n';
}
signed main(){
    SPEED;
    int t = 1;
    //cin >> t;
    for ( int cs = 1; cs <= t; cs++ ) {
        solve();
    }
    return 0;
}