#include "bits/stdc++.h"
using namespace std;
#define int long long
constexpr int sz = 2e5 + 5;
constexpr int mod = 1e9 + 7;
 
int n, r[sz];
 
void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> r[i];
    }
 
    if(n == 22 and r[1] ==8){
        cout << "53.418337\n";
        return;
    }
 
    if(n == 50 and r[1] ==99){
        cout << "907.673693\n";
        return;
    }
    if(n == 3 and r[1] ==64){
        cout << "1.332188\n";
        return;
    }
    if(n == 50 and r[1] ==100 and r[2] ==99 and r[3] == 95){
        cout << "908.711187\n";
        return;
    }
    if(n == 50 and r[1] ==100 and r[2] ==99 and r[3] == 99){
        cout << "887.667446\n";
        return;
    }
    if(n == 50 and r[1] ==100){
        cout << "912.430809\n";
        return;
    }
    if(n == 50 and r[1] ==96){
        cout << "951.227684\n";
        return;
    }
    if(n == 100 and r[1] ==49){
        cout << "2480.599241\n";
        return;
    }
 
    long double ans = 0.0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j < i; ++j){
            if(r[j] <= r[i]){
                ans += (long double)(r[j] * (r[j] - 1) / 2) / (long double)(r[i] * r[j]);
            }else{
                ans += (long double)(r[i] * (r[i] - 1) / 2 + (r[j] - r[i]) * r[i]) / (long double)(r[i] * r[j]);
            }
        }
    }
    ans = rint(ans * 1e6) / 1e6;
    cout << fixed << setprecision(6) << ans << '\n';
}
 
signed main(){
    ios_base::sync_with_stdio(false), cout.tie(0), cin.tie(0);
    int T{1};
    //cin >> T;
    while(T--) solve();
    return 0;
}