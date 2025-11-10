#include "bits/stdc++.h"
using namespace std;
 
#define int long long
 
constexpr int mod = 1e9 + 7;
 
int n, subfactorial[1000005];
 
signed main() {
    ios_base::sync_with_stdio(false), cout.tie(0), cin.tie(0);
    cin >> n;
    subfactorial[0] = 1;
    subfactorial[1] = 0;
    for (int i = 2; i <= n; i++) {
        subfactorial[i] = (i - 1) * ((subfactorial[i - 1] + subfactorial[i - 2]) % mod) % mod;
    }
    cout << subfactorial[n] << '\n';
    return 0;
}