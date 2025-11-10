#include "bits/stdc++.h"
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
constexpr int sz = 1e5 + 5;
constexpr int mod = 1e9 + 7;
constexpr int inf = 1e18 + 7;
 
int qpow(int a, int b) {
    int res = (a %= mod, 1);
    while(b){
        if(b & 1) res = res * a % mod;
        a = (b >>= 1, a * a % mod);
    }
    return res;
}
 
/*
0 -> no solution
1 -> unique solution
2 -> multiple solution
*/
 
int gauss(vector<vector<int>> a, vector<int> &ans){ /// https://cp-algorithms.com/linear_algebra/linear-system-gauss.html
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;
 
    vector<int> where (m, -1);
    for(int col = 0, row = 0; col < m && row < n; ++col){
        int sel = row;
        for(int i = row; i < n; ++i){
            if(a[i][col] != 0){
              sel = i;
              break;
            }
        }
 
        if(!a[sel][col]) continue;
 
 
 
        for(int i = col; i <= m; ++i) swap(a[sel][i], a[row][i]);
        where[col] = row;
 
        int inv_pivot = qpow(a[row][col], mod - 2) % mod;
        for(int i = 0; i < n; ++i){
          if(i ^ row){
            int c = (a[i][col] * inv_pivot) % mod;
            for(int j = col; j <= m; ++j){
              a[i][j] = (a[i][j] - c * a[row][j]) % mod;
              if(a[i][j] < 0) a[i][j] += mod;
            }
          }
        }
        ++row;
    }
 
    ans.assign(m, 0);
    for(int i = 0; i < m; ++i){
      if(where[i] != -1){
        ans[i] = a[where[i]][m] * qpow(a[where[i]][i], mod - 2) % mod;
      }
    }
 
    for(int i = 0; i < n; ++i){
        int sum = 0;
        for(int j = 0; j < m; ++j) sum = (sum + ans[j] * a[i][j]) % mod;
        if(sum != a[i][m]) return 0;
    }
 
    for(int i = 0; i < m; ++i) if(where[i] == -1) return 2;
    return 1;
}
 
void solve(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m + 1));
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m + 1; ++j){
      cin >> a[i][j];
    }
  }
 
  vector<int> ans;
  int res = gauss(a, ans);
  if(!res){
    cout << -1 << '\n';
  }else{
    for(int i = 0; i < m; ++i){
      cout << ans[i] << " \n"[i == (m - 1)];
    }
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