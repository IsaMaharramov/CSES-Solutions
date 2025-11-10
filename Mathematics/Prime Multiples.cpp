#include "bits/stdc++.h"
using namespace std;
 
#define int long long
 
int n, k, a[21], ans;
 
signed main() {
    ios_base::sync_with_stdio(false), cout.tie(0), cin.tie(0);
    cin >> n >> k;
    for (register int i = 1; i <= k; ++i) {
        cin >> a[i];
    }
    for (register int mask = 1; mask < (1 << k); ++mask) {
        unsigned long long cur = 1;
        int cnt(0);
        for (register int i = 0; i < k; ++i) {
            if (mask & (1 << i)) {
                cnt++;
                if (a[i + 1] > n / cur) cur = n + 1;
                else cur *= a[i + 1];
            }
        }
        ans += (cnt & 1 ? 1 : -1) * (n / cur);
    }
    cout << ans << '\n';
    return 0;
}