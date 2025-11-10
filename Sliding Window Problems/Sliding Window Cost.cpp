#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define intt long long
#define int intt
#define eb emplace_back
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<intt,intt>
#define ld long double
#define ordered_set tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) x.begin(), x.end()
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
constexpr int sz = 2e5 + 5;
 
int n, k, x[sz];
ordered_set ost;
 
signed main(){
    fastio;
    cin >> n >> k;
 
    for(register int i = 0; i < n; ++i){
        cin >> x[i];
    }
 
    for (register int i = 0; i < k - 1; ++i) {
        ost.insert({x[i], i});
    }
 
    int med(k >> 1), lsum(0), rsum(0);
 
    for (register int i = 0; i < k - 1; ++i) {
        if (i < med) {
            lsum += ost.find_by_order(i)->F;
        }else {
            rsum += ost.find_by_order(i)->F;
        }
    }
 
    auto ins = [&](pii p) {
        ost.insert(p);
 
        int idx = ost.order_of_key(p);
 
        if (idx < med) {
            int median = ost.find_by_order(med)->F;
            lsum -= median;
            rsum += median;
            lsum += p.F;
        }else {
            rsum += p.F;
        }
 
    };
 
    auto rem = [&](pii p) {
        int idx = ost.order_of_key(p);
 
        if (idx < med) {
            int median = ost.find_by_order(med)->F;
            lsum += median;
            rsum -= median;
            lsum -= p.F;
        }else {
            rsum -= p.F;
        }
 
        ost.erase(p);
    };
 
    for (register  int i = k - 1; i < n; ++i) {
        ins({x[i], i});
 
        int median = ost.find_by_order(med)->F;
 
        int ans = median * (med - 1) - lsum;
 
        ans += rsum - median * (k - med - 1);
 
        cout << ans << ' ';
 
        rem({x[i - k + 1], i - k + 1});
    }
 
 
 
}