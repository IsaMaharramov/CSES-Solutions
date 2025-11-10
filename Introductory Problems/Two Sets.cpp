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
ll sm1, sm2;
set<int> otos, ops;
 
signed main(){
    SPEED;
    cin >> n;
    if(n <= 2){
        cout << "NO" << '\n';
        return 0;
    }
    int l{1}, r{n - (n & 1)};
    while(l < r){
        if(l & 1){
            otos.insert(l), otos.insert(r);
            sm1 += (l + r);
        }else{
            ops.insert(l), ops.insert(r);
            sm2 += (l + r);
        }
        ++l, --r;
    }
    if(sm1 < sm2){
        otos.insert(n);
        sm1 += n;
    }else if(sm2 < sm1){
        ops.insert(n);
        sm2 += n;
    }
    ll sm = 1ll * n * (n + 1);
    sm >>= 1;
    if((sm1 ^ sm2) || (sm ^ (sm1 + sm2))){
        cout << "NO" << '\n';
    }else{
        cout << "YES" << '\n';
        cout << (int)otos.size() << '\n';
        for(auto &tot : otos){
            cout << tot << ' ';
        }
        cout << '\n' << (int)ops.size() << '\n';
        for(auto &tot : ops){
            cout << tot << ' ';
        }
    }
}