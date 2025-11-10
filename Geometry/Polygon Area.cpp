#include "bits/stdc++.h"
using namespace std;
#define int long long
constexpr int sz = 2e5 + 5;
constexpr int mod = 1e9 + 7;
 
struct Point{
    int x, y;
} p[1 << 10];
 
istream& operator>>(istream& in, Point& p){
    in >> p.x >> p.y;
    return in;
}
 
int n, ans;
 
void solve(){  /// https://en.wikipedia.org/wiki/Shoelace_formula
    cin >> n;
    for(int i(0); i < n; ++i){
        cin >> p[i];
    }
    for(int i(0); i < n; ++i){
        ans += (p[i].x * p[(i + 1) % n].y) - (p[(i + 1) % n].x * p[i].y);
    }
    cout << abs(ans) << '\n';
}
 
signed main(){
    ios_base::sync_with_stdio(false), cout.tie(0), cin.tie(0);
    int T{1};
    //cin >> T;
    while(T--) solve();
    return 0;
}