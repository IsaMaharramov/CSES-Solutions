#include "bits/stdc++.h"
using namespace std;
 
signed main() {
    ios_base::sync_with_stdio(false), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int res(0);
        for (int i = 0, a; i < n; ++i) {
            cin >> a;
            res ^= a;
        }
        puts((res ? "first" : "second"));
    }
    return 0;
}