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
#define y1 y_1
 
//using namespace __gnu_pbds;
//template<class T> using ost = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
using namespace std;
using ld = long double;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
inline void setIn(string s) { freopen(s.c_str(), "r", stdin); }
inline void setOut(string s) { freopen(s.c_str(), "w", stdout); }
inline void Setall(string s){setIn(s+".in"); setOut(s+".out"); }
 
const int sz = 2e5 + 5;
 
int n;
int a[sz], idx[sz];
 
signed main(){
    SPEED;
    cin >> n;
    for(register int i = 1; i <= n; ++i){
        cin >> a[i];
        idx[a[i]] = i;
    }
    int ans{1};
    for(register int i = 2; i <= n; ++i){
        ans += (idx[i] < idx[i - 1]);
    }
    cout << ans << '\n';
    return 0;
}