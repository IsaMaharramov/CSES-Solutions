#include "bits/stdc++.h" 
using namespace std;
 
// #define int long long
constexpr int sz = 2e5 + 5;
 
int n, a[sz], b[sz];
bitset<sz> sieve;
set<int> st;
vector<int> p;
 
void precomp(){
    for(int i = 2; i < sz; ++i){
        if(sieve[i]) continue;
        for(int j = (i << 1); j < sz; j += i) sieve[j] = 1;
        p.emplace_back(i);
    }
}
 
void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i) st.insert(i);
    for(int i = n; i; --i){
        if(st.find(i) == st.end()) continue;
        auto it = lower_bound(p.begin(), p.end(), (i << 1));
        int j = *it - i;
        while(st.find(j) == st.end() and it != p.begin()) j = *(--it) - i;
        a[(int)st.size()] = (b[(int)st.size()] = j, i);
        if(i ^ j) a[(int)st.size() - 1] = (b[(int)st.size() - 1] = i, j);
        st.erase(i), st.erase(j);
    }
    for(int i = 1; i <= n; ++i) cout << a[i] << " \n"[i == n];
    for(int i = 1; i <= n; ++i) cout << b[i] << " \n"[i == n];
    return;   
}
 
signed main(){
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    precomp();  
    //cin >> t;
    while(t--) solve();
    return 0;
}