#include "bits/stdc++.h"
using namespace std;
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define all(x) x.begin(),x.end()
constexpr int sz = 2e5 + 5;
constexpr int mod = 1e9 + 7;
 
int n, tree[sz], ans;
map<int, vector<int>> mp;
 
void update(int pos, int val){
    while(pos <= n) pos += (tree[pos] += val, (pos & (-pos)));
}
 
inline int get_ans(int l, int r){
    if(r < l) return 0ll;
    if(l ^ 1) return get_ans(1, r) - get_ans(1, l - 1);
    int res = 0;
    while(r) r -= (res += tree[r], r & (-r));
    return res;
}
 
void solve(){
    cin >> n;
    vector<int> A(n);
    for(int &j : A) cin >> j;
    for(int i = 0; i < n; ++i) mp[A[i]].emplace_back(i);
    for(auto &to : mp){
        vector<int> v;
        for(int &j : to.S) v.emplace_back((get_ans(1, j) + 1) % mod);
        for(int i = 0; i < (int)to.S.size(); ++i) ans = (update(to.S[i] + 1, v[i]), (ans + v[i]) % mod);
    }
    cout << ans << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false), cout.tie(0), cin.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}