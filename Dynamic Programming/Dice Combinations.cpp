#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD=1e9+7;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	vector<ll> dp(n+1);
	dp[0]=1;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=6; ++j){
			if(i-j>=0){
				dp[i]=(dp[i]+dp[i-j])%MOD;
			}
		}
	}
	cout<<dp[n]%MOD<<'\n';
	return 0;
}