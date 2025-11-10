#include<bits/stdc++.h>
 
#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif
 
using namespace std;
 
constexpr int sz = 1e5 + 5;
 
constexpr int mod = 1e9 + 7;
 
#define int unsigned long long
 
int mpow(int n, int k){
	if(!k) return 1ull;
	n %= mod;
	if(k & 1) return (n % mod) * mpow(n, k - 1) % mod;
	else return mpow(n * n % mod, (k >> 1)) % mod;
}
 
signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int TT;
	cin >> TT;
	while(TT--){
		int A, B;
		cin >> A >> B;
		cout << mpow(A, B) % mod << '\n';
	}
	return 0;
}