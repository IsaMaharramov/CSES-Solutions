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
const int inf = 1e18+7;
const int mod = 1e9 + 7;
int i,j;
int n, p[sz];
void solve(){
    cin >> n;
    int tot(0);
    for(i = 1; i <= n; ++i){
        cin >> p[i];
        tot ^= (~i & 1) * p[i];
    }
    cout << (tot ? "first" : "second") << '\n';
}
signed main(){
    SPEED;
    int TT{1};
    cin >> TT;
    while(TT--) solve();
    return 0;
}