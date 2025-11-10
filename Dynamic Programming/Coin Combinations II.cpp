#include<iostream>
#include<vector>
#include<random>
#include<chrono>
#include<algorithm>
#define SPEED ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define oo 1000000001
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define ll long long
#define ull unsigned long long
 
using namespace std;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int sz = 110, MAX = 1e7, mod = 1e9 + 7;
 
#define int ll
 
int n, x;
int c[sz];
 
int dp[MAX];
 
signed main(){
	SPEED;
	cin >> n >> x;
	for(register int i = 1; i <= n; ++i){
        cin >> c[i];
	}
	n = unique(c+1, c+n+1) - c - 1;
	dp[0] = 1;
	for(register int i = 1; i <= n; ++i){
        for(register int j = c[i]; j <= x; ++j){
            dp[j] += dp[j - c[i]];
            dp[j] %= mod;
        }
	}
	cout << dp[x] % mod << '\n';
	return 0;
}