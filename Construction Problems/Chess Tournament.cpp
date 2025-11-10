#include "bits/stdc++.h"
using namespace std;
 
//#define int long long
 
vector<pair<int, int>> ans, em;
priority_queue<pair<int, int>> q;
 
void solve(){
    int n;
    cin >> n;
    for(int i = 1, x; i <= n; ++i){
        cin >> x;
        q.push({x, i});
    }
    while(!q.empty()){
        int x = q.top().first, i = q.top().second;
        q.pop();
        em.clear();
        register int j(0);
        while(j < x){
            if(!q.top().first) return puts("IMPOSSIBLE"), void(0);
            ans.emplace_back(pair<int, int>{q.top().second, i});
            em.emplace_back(pair<int, int>{q.top().first - 1, q.top().second});
            q.pop();
            ++j;
        }
        for(auto &to : em) q.push(to);
    }
    cout << (int)ans.size() << '\n';    
    for(auto &to : ans) cout << to.first << ' ' << to.second << '\n';
    return;
}
 
 
signed main(){
    int t = 1;
//    cin>>t;
    while(t--) solve();
    return 0;
}