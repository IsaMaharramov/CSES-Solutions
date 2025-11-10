#include "bits/stdc++.h"
using namespace std;
constexpr int sz = 1e6 + 6;
constexpr int mod = 1e9 + 7;
#define int long long
int k;
long double dp[1 << 3][1 << 3][1 << 7], ans[1 << 3][1 << 3];
array<int, 4> dx = {-1, 1, 0, 0}, dy = {0, 0, 1, -1};
void solve(){
    cin >> k;
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            ans[i][j] = 1;
        }
    }
 
    function<bool(int, int)> OK = [&](int x, int y)->bool{ return (min(x, y) >= 0 and max(x, y) < 8); };
 
    for(int start_y = 0; start_y < 8; ++start_y){
        for(int start_x = 0; start_x < 8; ++start_x){
            dp[start_y][start_x][0] = 1.0;
            for(int step = 0; step < k; ++step){
                for(int y = 0; y < 8; ++y){
                    for(int x = 0, cnt_dir = 0; x < 8; ++x){
                        for(int i = 0; i < 4; ++i) cnt_dir += OK(x + dx[i], y + dy[i]);
                        for(int i = 0; i < 4; ++i){
                            int tox = x + dx[i], toy = y + dy[i];
                            if(!OK(tox, toy)) continue;
                            dp[toy][tox][step + 1] += dp[y][x][step] / cnt_dir;
                        }
                        cnt_dir = 0;
                    }
                }
            }
 
            for(int y = 0; y < 8; ++y){
                for(int x = 0; x < 8; ++x){
                    ans[y][x] *= (1 - dp[y][x][k]);
                }
            }
 
 
            for(int step = 0; step <= k; ++step){
                for(int y = 0; y < 8; ++y){
                    for(int x = 0; x < 8; ++x){
                        dp[y][x][step] = 0;
                    }
                }
            }
 
 
        }
    }
 
 
    
    long double expected_number = 0.0;
    for(int y = 0; y < 8; ++y){
        for(int x = 0; x < 8; ++x){
            expected_number += ans[y][x];
        }
    }
    expected_number = rint(expected_number * 1e6) / 1e6; /// https://en.cppreference.com/w/cpp/numeric/math/rint.html
    cout << fixed << setprecision(6) << expected_number << '\n';
} 
signed main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T{1};
    //cin >> T;
    while(T--) solve();
    return 0;
}