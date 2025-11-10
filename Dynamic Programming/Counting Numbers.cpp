#include "bits/stdc++.h"
using namespace std;
#define int long long
constexpr int sz = 2e5 + 5;
constexpr int mod = 1e9 + 7;
 
 
int dp[2][2][10][20];
 
int f(string s, int cur, int prev_digit = -1, int lz = 1, int c = 1){
 
    if(!cur) return 1;
 
    if(dp[c][lz][prev_digit][cur] != -1) return dp[c][lz][prev_digit][cur];
 
    int limit = (!c ? 9 : (s[(int)s.size() - cur] - 48));
 
    int res = 0;
 
    for(int x = 0; x <= limit; ++x){
 
        if(!(!lz && (x == prev_digit))) res += f(s, cur - 1, x, ((lz && !x) ? 1 : 0), ((x == limit && c) ? 1 : 0));
    
    }
 
    return dp[c][lz][prev_digit][cur] = res;
}
 
int a, b, cr, cl;
 
void solve(){
    cin >> a >> b;
    --a;
    string sa = to_string(a);
    string sb = to_string(b);
 
    memset(dp, -1, sizeof(dp));
    if(a) cl = f(sa, (int)sa.size());
 
    memset(dp, -1, sizeof(dp));
    cr = f(sb, (int)sb.size());
 
    cout << cr - cl - !a << '\n';
 
}
 
signed main(){
    ios_base::sync_with_stdio(false), cout.tie(0), cin.tie(0);
    int T{1};
    //cin >> T;
    while(T--) solve();
    return 0;
}