#include<iostream>
#include<vector>
#include<random>
#include<chrono>
#include<algorithm>
#include<set>
#include<map>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
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
#define left lefttt
#define right righttt
//#define int long long
 
//using namespace __gnu_pbds;
//template<class T> using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
using namespace std;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int sz = 25;
 
int n;
 
int p[sz];
 
signed main(){
    SPEED;
    cin >> n;
    ll sm(0);
    for(register int i = 1; i <= n; ++i){
        cin >> p[i], sm += p[i];
    }
    ll ans = oo;
    for(register int mask = 0; mask < (1 << n); ++mask){
        ll tot(0);
        for(register int i = 1; i <= n; ++i){
            if(((1 << i) & mask)){
                tot += p[i];
            }
        }
        ans = min(ans, abs((tot << 1) - sm));
    }
    cout << ans << '\n';
    return 0;
}