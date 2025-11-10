#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
ll Kadane_Algorithm(vector<int>& a){
    int n = (int)a.size();
    if(!n) return 0;
    vector<ll> dp(n);
    ll res = a[0];
    dp[0] = a[0];
    for(register int i = 1; i < n; ++i){
        dp[i] = max(0ll, dp[i-1]) + a[i];
        res = max(res,dp[i]);
    }
    return res;
}
int main(){
    cin.tie()->sync_with_stdio();
    int n;
    cin >> n;
    vector<int> a(n);
    for(register int i = 0; i < n; ++i){
        cin >> a[i];
    }
    cout << Kadane_Algorithm(a) << '\n';
    exit(0);
}