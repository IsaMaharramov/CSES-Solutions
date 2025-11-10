#include<iostream>
#include<vector>
#include<random>
#include<chrono>
#include<algorithm>
#include<set>
#include<map>
#include<bitset>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define SPEED ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define in(x) scanf("%d",&x)
#define IN(x) scanf("%I64d",&x)
#define oo 1000000001
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define ll long long
#define ull unsigned long long
#define left lefttt
#define right righttt
#define y1 y_1
 
//using namespace __gnu_pbds;
//template<class T> using ost = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
using namespace std;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int sz = 2e5 + 5, MAX = 1e5 + 1;
 
#define int ll
 
int n;
int a[sz];
 
bitset<MAX> dp;
 
signed main(){
    SPEED;
    in(n);
    for(register int i = 1; i <= n; ++i){
        in(a[i]);
    }
    dp[0] = true;
    for(register int i = 1; i <= n; ++i){
        dp |= (dp << a[i]);
    }
    cout << (int)dp.count() - 1 << '\n';
    for(register int i = 1; i < MAX; ++i){
        if(dp[i]) cout << i << ' ';
    }
    return 0;
}