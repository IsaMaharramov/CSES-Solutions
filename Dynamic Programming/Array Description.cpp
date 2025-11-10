#include<iostream>
#include<vector>
#include<queue>
#include<random>
#include<chrono>
#include<algorithm>
#include<set>
#define SPEED ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define oo 1000000001
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define ll long long
#define ull unsigned long long
 
using namespace std;
using ld = long double;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#define int ll
 
const int sz = 1e5 + 5;
const int mod = 1e9 + 7;
 
int n, m;
int a[sz];
int dp[1 << 7][sz];
 
signed main(){
    SPEED;
    cin >> n >> m;
    for(register int i = 1; i <= n; ++i) cin >> a[i];
    if(!a[1]) for(register int i = 1; i <= m; ++i) dp[i][1] = 1;
    else dp[a[1]][1] = 1;
    for(register int i = 2; i <= n; ++i){
        if(a[i]){
            dp[a[i]][i] += (dp[a[i] - 1][i-1] + dp[a[i] + 1][i-1]) % mod + dp[a[i]][i-1];
            dp[a[i]][i] %= mod;
        }else{
            for(register int j = 1; j <= m; ++j){
                dp[j][i] += (dp[j - 1][i-1] + dp[j + 1][i-1]) % mod + dp[j][i-1];
                dp[j][i] %= mod;
            }
        }
    }
    int ans(0);
    for(register int i = 1; i <= m; ++i) ans += dp[i][n], ans %= mod;
    cout << ans << '\n';
    return 0;
}