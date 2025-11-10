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
 
const int sz = 2e5 + 5;
 
int n, x;
multiset<int> st;
set<int> otos;
map<int, int> maximums;
 
signed main(){
    SPEED;
    cin >> x >> n;
    st.insert(0);
    st.insert(x);
    maximums[x]++;
    maximums[0] = oo;
    otos.insert(x);
    otos.insert(0);
    int mx(0), prev{0};
    for(register int i = 1, a; i <= n; ++i){
        cin >> a;
        auto it = st.lower_bound(a);
        int nxt = *it;
        --it;
        int prev = *it;
        int cur = a;
        int dif = nxt - prev;
        maximums[dif]--;
        if(maximums[dif] <= 0) otos.erase(dif);
        otos.insert(nxt - cur), otos.insert(cur - prev);
        maximums[cur - prev]++, maximums[nxt - cur]++;
        auto ans = otos.rbegin();
        cout << *ans << ' ';
        st.insert(a);
    }
 
 
}