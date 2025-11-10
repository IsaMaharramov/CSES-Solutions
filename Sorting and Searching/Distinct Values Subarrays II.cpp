#include<bits/stdc++.h>
using namespace std;
int n, k, x[200020];
map<int, int> cnt;
long long ans;
signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for(register int i = 1; i <= n; ++i){
		cin >> x[i];
	}
	int l(1), r(1), tot(1);
	cnt[x[l]]++;
	while(l <= n){
		
		while(r + 1 <= n && tot + !cnt[x[r+1]] <= k){
			++r;
			cnt[x[r]]++;
			tot += cnt[x[r]] == 1;
		}
		ans += r - l + 1;
		
		if(cnt[x[l]] == 1) --tot;
		cnt[x[l]]--;
		++l;
		
	}
	
	cout<<ans<<'\n';
	
}