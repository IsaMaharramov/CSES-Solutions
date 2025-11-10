#include<iostream>
#include<vector>
#include<random>
#include<chrono>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_set>
#define SPEED ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define oo 1000000001
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define ll long long
#define ull unsigned long long
 
using namespace std;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int sz = 2e5 + 5, MOD = 1e9 + 7;
 
#define int ll
 
int n;
 
signed main(){
    SPEED;
    cin >> n;
    int res{1};
    for(register int i = 1; i <= n; ++i){
        res <<= 1;
        if(res >= MOD) res -= MOD;
    }
    cout << res % MOD << '\n';
    return 0;
}
