// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include "bits/stdc++.h"
using namespace std;
#define int long long
constexpr int sz = 2e5 + 5;
constexpr int mod = 1e9 + 7;
constexpr int inf = 1e18 + 7;
 
void print(__int128 x){
    if (x < 0){
        putchar('-');
        x = -x;
    }
    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
 
__int128 get_sm(vector<int>& arr){
    __int128 total = 0;
    __int128 prefix_sum = 0;
    for(int i = 0; i < (int)arr.size(); ++i){
        total += (__int128)i * (__int128)arr[i] - prefix_sum;
        prefix_sum += (__int128)arr[i];
    }
    return total;
}
 
void solve(){
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for(int i = 0; i < n; ++i){
    cin >> x[i] >> y[i];
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  __int128 total_x = get_sm(x);
  __int128 total_y = get_sm(y);
  __int128 result = total_x + total_y;  
  print(result);
  cout << "\n";
 
}
 
signed main(){
  cout.tie(0)->sync_with_stdio(0);
  cin.tie(0)->sync_with_stdio(0);
  int T{1};
  //cin >> T;
  while(T--) solve();
  return 0;
}