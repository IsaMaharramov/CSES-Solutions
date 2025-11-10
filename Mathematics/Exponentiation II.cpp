#include "bits/stdc++.h"
using namespace std;
 
constexpr int mod = 1e9 + 7;
 
#define int long long
 
int a, b, c;
 
inline int f(int n, int k, int m){
	if(k == 0) return 1;
	n %= m;
	if(k & 1) return n * f(n, k - 1, m) % m;
	n = n * n % m;
	k >>= 1;
	return f(n, k, m) % m;
}
 
inline void solve(){
	cin >> a >> b >> c;
	cout << f(a, f(b, c, mod - 1), mod) << '\n';
}
 
signed main(){
	ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
	int TT;
	cin >> TT;
	while(TT--) solve();
}