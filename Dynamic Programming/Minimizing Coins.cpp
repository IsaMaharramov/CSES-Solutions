#include<iostream>
#include<vector>
using namespace std;
const int inf = 1e9;
int main(){
    cin.tie()->sync_with_stdio();
    int n, x;
    cin >> n >> x;
    vector<int> c(n+1);
    for(register int i = 1; i <= n; ++i){
        cin >> c[i];
    }
    vector<int> dp(x+1, inf);
    dp[0] = 0;
    for(int i = 0; i <= x; ++i){
        for(int j = 1; j <= n; ++j){
           if(i+c[j] <= x) dp[i + c[j]] = min(dp[i + c[j]], dp[i] + 1);
        }
    }
    if(dp[x] != inf){
        cout << dp[x] << '\n';
    }else{
        puts("-1");
    }
    exit(0);
}