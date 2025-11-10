#include<iostream>
#include<vector>
#include<random>
#include<chrono>
#include<algorithm>
#include<set>
#include<map>
#include<ios>
#include<cstring>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define SPEED ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define oo 1000000001
#define in(x) scanf("%d",&x)
#define IN(x) scanf("%ld",&x)
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
 
const int sz = 1e5 + 5;
 
int n, x;
int a[sz];
map<int, set<int>> mp;
 
signed main(){
    SPEED;
    cin >> n >> x;
    for(register int i = 1; i <= n; ++i){
        cin >> a[i];
        mp[a[i]].insert(i);
    }
    sort(a+1, a+n+1);
    for(register int i = 1; i <= n - 2; ++i){
        int need = x - a[i], l = i + 1, r = n;
        while(l < r){
            int sm = a[l] + a[r];
            if(sm == need){
                int ans1 = *mp[a[i]].begin();
                auto it = mp[a[l]].begin();
                auto itr = mp[a[r]].begin();
                int ans2{*it}, ans3{*itr};
                if((*it) ^ ans1) ans2 = *it;
                else ans2 = *(++it);
                while((*itr) == ans1 || (*itr) == ans2) ans3 = *(++itr);
                cout << ans1 << ' ' << ans2 << ' ' << ans3 << '\n';
                return 0;
            }else if(sm < need){
                ++l;
            }else{
                --r;
            }
        }
    }
    cout << "IMPOSSIBLE" << '\n';
    return 0;
}
