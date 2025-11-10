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
 
int n, m;
 
multiset<int> st;
map<int, int> mp;
 
signed main(){
    SPEED;
    cin >> n >> m;
    for(register int i = 1, a; i <= n; ++i){
        cin >> a;
        st.insert(a);
        mp[a]++;
    }
    for(register int i = 1, b; i <= m; ++i){
        cin >> b;
        auto it = st.upper_bound(b);
        if(it == st.begin()){
            cout << -1 << '\n';
            continue;
        }
        --it;
        cout << *it << '\n';
        mp[*it]--;
        if(!mp[*it]) st.erase(*it);
    }
    return 0;
}