#include "bits/stdc++.h"
using namespace std;

#define int long long

int fact[21];

inline void find_permutation(int n, int k){
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    int kp{k - 1};
    vector<int> res;
    for(int i = n; i >= 1; --i){
        int F = fact[i - 1];
        int idx = kp / F;
        res.emplace_back(a[idx]);
        a.erase(a.begin() + idx);
        kp %= F;
        if(!kp){
            for(int &x : a) res.emplace_back(x);
            break;
        }
    }
    for(int i = 0; i < n; ++i) cout << res[i] << ' ';
    cout << '\n';
    return;
}

inline void find_order(int n){
    vector<int> p(n);
    for(int &j : p) cin >> j;
    vector<bool> a(n + 1, true);
    int kp = 0;  // 
    for(int i = 0; i < n; ++i){
        int cur = p[i], smc = 0;
        for(int j = 1; j < cur; ++j){
            smc += (a[j]);
        }
        kp += smc * fact[n - i - 1];
        a[cur] = false;
    }
    cout << kp + 1 << '\n';
    return;
}

void solve(){
    int type, n;
    cin >> type >> n;
    if(type ^ 1){
        find_order(n);
    }else{
        int k = (cin >> k, k);
        find_permutation(n, k);
    }
    return;
}

signed main(){
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    fact[0] = 1;
    for(int i = 1; i <= 20; ++i){
        fact[i] = fact[i - 1] * i;
    }
    cin >> t;
    while(t--) solve();
    return 0;
}