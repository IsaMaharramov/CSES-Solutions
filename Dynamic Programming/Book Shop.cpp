#include<iostream>
#include<random>
#include<chrono>
#include<vector>
#include<algorithm>
#define SPEED ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define oo 1000000001
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define pb push_back
#define ll long long
 
using namespace std;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int sz = 1e5 + 5;
 
int n, x;
 
int h[sz], s[sz];
 
int dp[sz];
 
signed main(){
    SPEED;
    cin >> n >> x;
    for(register int i = 1; i <= n; ++i) cin >> h[i];
    for(register int i = 1; i <= n; ++i) cin >> s[i];
    for(register int i = 1; i <= n; ++i){
        for(int j = x; j >= h[i]; --j){
            dp[j] = max(dp[j], dp[j - h[i]] + s[i]);
        }
    }
    cout << *max_element(dp+1, dp+x+1) << '\n';
    return 0;
}
