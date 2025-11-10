#include<bits/stdc++.h>
using namespace std;
 
#define intt long long
#define eb emplace_back
 
constexpr int sz = 2e5 + 5;
constexpr int inf = 1E9 + 100;
 
int n, x[sz], dp[sz];
 
inline void solve(){
	cin >> n;
	for(register int i = 1; i <= n; ++i){
		cin >> x[i], dp[i] = inf;
	}
	
	dp[0] = -inf;
	
	for(register int i = 1; i <= n; ++i){
		
		int l = upper_bound(dp, dp + n + 1, x[i]) - dp;
		
		if(dp[l] > x[i] && dp[l-1] < x[i]){
			dp[l] = x[i];
		}
		
		
		
	}
	
	int ans(0);
	
	
	for(register int i = 1; i <= n; ++i){
		if(dp[i] ^ inf) ans = i;
	}
	
	cout << ans << '\n';
	
}
 
 
signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}