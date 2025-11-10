// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include "bits/stdc++.h"
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
constexpr int sz = 1e5 + 5;
constexpr int mod = 1e9 + 7;
constexpr int inf = 1e9 + 7;
 
int n, q, a[sz], nextt[20][sz];
 
/*
4 1 2 2 3
 
*/
 
 
void solve(){
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        nextt[0][i] = i + 1;
    }
  a[n + 1] = inf;
  for(int i = 0; i < 20; ++i){
    nextt[i][n + 1] = n + 1;
  }
 
 
    for(int i = n; i; --i){
 
        while(nextt[0][i] <= n and a[i] >= a[nextt[0][i]]){
            nextt[0][i] = nextt[0][nextt[0][i]];
  
    }
 
    }
  
 
 
    for(int i = n; i; --i){
        for(int j = 1; j < 20; ++j){
            nextt[j][i] = nextt[j - 1][nextt[j - 1][i]];
        }
    }
 
    function<int(int, int)> query = [&](int l, int r)->int{
        assert(l <= r);
        int dif = r - l, res = 0;
        for(int j = 19; j >= 0; --j){
            if(nextt[j][l] <= r){
                l = nextt[j][l];
                res += (1 << j);
            }
        }
        return res;
    };
 
    int l, r;
    while(q--){
        cin >> l >> r;
        cout << query(l, r) + 1 << '\n';
    }
 
 
 
}
signed main(){
  cout.tie(0)->sync_with_stdio(0);
  cin.tie(0)->sync_with_stdio(0);
  int T{1};
  //cin >> T;
  while(T--) solve();
  return 0;
}