#include<bits/stdc++.h>
 
#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif
 
using namespace std;
 
constexpr int sz = 1e5 + 5;
 
signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int TT;
	cin >> TT;
	while(TT--){
		int N;
		cin >> N;
		unordered_map<int, int> mp;
		int M{N};
		for(register int i(2); i * i <= M; ++i){
			while(M % i == 0){
				mp[i]++;
				M /= i;
			}
		}
		if(M > 1) mp[M]++;
		int ans(1);
		for(auto &tot : mp){
			ans *= (tot.second + 1);
		}
		cout << ans << '\n';
	}
	return 0;
}