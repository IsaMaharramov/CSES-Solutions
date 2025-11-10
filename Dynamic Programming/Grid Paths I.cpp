#include<iostream>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
ll dp[1003][1003];
char grid[1003][1003];
int main(){
    cin.tie()->sync_with_stdio();
    int n;
    cin >> n;
    for(register int i = 1; i <= n; ++i){
        for(register int j = 1; j <= n; ++j){
            cin >> grid[i][j];
        }
    }
    for(register int i = 1; i <= n; ++i){
        if(grid[i][1] == '*') break;
        dp[i][1] = 1;
    }
    for(register int i = 1; i <= n; ++i){
        if(grid[1][i] == '*') break;
        dp[1][i] = 1;
    }
    for(int i = 2; i <= n; ++i){
        for(int j = 2; j <= n; ++j){
           if(grid[i][j] == '*') continue;
           dp[i][j] = (grid[i-1][j] != '*' ? dp[i-1][j] : 0) + (grid[i][j-1] != '*' ? dp[i][j-1] : 0);
           dp[i][j] = (dp[i][j] + MOD) % MOD;
        }
    }
    cout << (dp[n][n] + MOD) % MOD << '\n';
    exit(0);
}