/// https://www.cambridge.org/core/journals/mathematical-gazette/article/abs/10539-the-eureka-theorem-of-gauss/B85583C9C2DECC7D7F479B50E08869C0
#include "bits/stdc++.h"
using namespace std;
#define int long long
constexpr int sz = 2e5 + 5;
int n;
bool is_triangular(int x) {
    int disc = 1 + 8 * (long long)x;
    int root = sqrtl(disc);
    if(root * root != disc) return false;  // Not perfect square
    return (root - 1) % 2 == 0;             // (root - 1) must be even
}
/*
k*(k+1)/2 = n
k*(k+1) = 2n
k^2 + k - 2n = 0
k = (-1 + sqrt(1 + 8n)) / 2   
*/
void solve(){
    cin >> n;
    if(is_triangular(n)) return cout << 1 << '\n', void(0);
    for(int i = 1; i * (i + 1) / 2 <= n; ++i){
        int y = i * (i + 1) / 2;
        if(is_triangular(n - y)) return cout << 2 << '\n', void(0);
    }
    cout << 3 << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false), cout.tie(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}