#include "bits/stdc++.h"
using namespace std;
 
int n, q, f[30][200005];
 
signed main() {
    ios_base::sync_with_stdio(false), cout.tie(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> f[0][i];
    for (int j = 1; j < 30; ++j) {
        for (int i = 1; i <= n; ++i) f[j][i] = f[j-1][f[j-1][i]];
    }
    function<int(int, int)> get = [&](int a, int b)->int{
        for (int i = 0; i < 30; ++i) if (b & (1 << i)) a = f[i][a];
        return a;
    };
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << get(a, b) << '\n';
    }
}