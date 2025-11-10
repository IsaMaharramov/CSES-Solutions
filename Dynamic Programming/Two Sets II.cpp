#include<iostream>
#include<vector>
#include<random>
#include<chrono>
#include<algorithm>
#include<set>
#include<map>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define SPEED ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define in(x) scanf("%d",&x)
#define IN(x) scanf("%I64d",&x)
#define oo 1000000001
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define ll long long
#define ull unsigned long long
#define left lefttt
#define right righttt
#define y1 y_1
 
//using namespace __gnu_pbds;
//#define ordered_set  tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
using namespace std;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int sz = 501, MAX = 5e5, MOD = 1e9 + 7;
 
int n;
ull dp[sz][MAX];
 
signed main(){
    SPEED;
    cin >> n;
    ll sm = 1ll * n * (n + 1);
    sm >>= 1;
    if(sm & 1) return puts("0"), 0;
    sm >>= 1;
    dp[0][0] = 1;
    for(register int x = 0; x <= sm; ++x){
        for(register int i = 1; i < n; ++i){
            if(x - i >= 0) dp[i][x] = dp[i-1][x] + dp[i-1][x-i];
            else dp[i][x] = dp[i-1][x];
            dp[i][x] = (dp[i][x] + MOD) % MOD;
        }
    }
    cout << dp[n-1][sm] % MOD << '\n';
    return 0;
}