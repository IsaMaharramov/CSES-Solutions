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
 
const int sz = 1e6 + 5, mod = 1e9 + 7;
 
int dp[2][sz];
 
int n;
 
inline void pre_comp(){
    dp[0][1] = dp[1][1] = 1;
    for(register int i = 2; i < sz; ++i){
        dp[0][i] = (dp[0][i-1] << 1) + dp[1][i-1], dp[0][i] %= mod;
        dp[1][i] = (dp[1][i-1] << 2) + dp[0][i-1], dp[1][i] %= mod;
    }
    return;
}
 
signed main(){
    SPEED;
    int T;
    cin >> T;
    pre_comp();
    auto test_case = [&](){
        cin >> n;
        cout << (dp[0][n] + dp[1][n]) % mod << '\n';
        return;
    };
    while(T--) test_case();
    return 0;
}