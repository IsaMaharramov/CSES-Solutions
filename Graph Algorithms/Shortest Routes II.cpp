#include<bits/stdc++.h>
 
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) void(37)
#endif
 
inline void readInt(int &n){
    char ch;
    int sign = 1;
    while(ch = getchar(), isspace(ch)){//getchar()-->getchar_unlocked()
 
    };
    n = 0;
    if(ch == '-')
        sign = -1;
    else n = ch - '0';
    while(ch = getchar(), isdigit(ch))
        n = (n << 3) + (n << 1) + ch - '0';
    n *= sign;
}
 
using namespace std;
 
constexpr long long inf = 1e18 + 7;
 
int n, m, q;
 
signed main(){
	
	readInt(n), readInt(m), readInt(q);
	
	vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, inf));
	
	for(register int i = 1; i <= n; ++i) dp[i][i] = 0ll;
	
	for(register int i = 1, a, b, c; i <= m; ++i) readInt(a), readInt(b), readInt(c), dp[a][b] = dp[b][a] = min(dp[a][b], (long long)c);
	
	for(register int k = 1; k <= n; ++k){
		for(register int j = 1; j <= n; ++j){
			for(register int i = 1; i <= n; ++i){
				
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
				
			}
		}
	}
	
	int a, b;
	
	while(q--){
		readInt(a), readInt(b);
		cout << (dp[a][b]^inf ? dp[a][b] : -1) << '\n';
	}
	
	
}