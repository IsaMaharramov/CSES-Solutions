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
 
//using namespace __gnu_pbds;
//template<class T> using ost = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
using namespace std;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//void setIn(string s) { freopen(s.c_str(), "r", stdin); }
//void setOut(string s) { freopen(s.c_str(), "w", stdout); }
 
const int sz = 2e5 + 5;
 
int n, m, k;
 
int a[sz], b[sz];
 
signed main(){
    SPEED;
    cin >> n >> m >> k;
    for(register int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for(register int i = 1; i <= m; ++i){
        cin >> b[i];
    }
    sort(a+1,a+n+1); sort(b+1,b+m+1);
    int i = 1, j = 1, ans(0);
    while(i <= n && j <= m){
        if(a[i] - k <= b[j] && b[j] <= a[i] + k){
            ++ans, ++i, ++j;
        }else if(b[j] < a[i] - k){
            ++j;
        }else{
            ++i;
        }
    }
    cout << ans << '\n';
    return 0;
}