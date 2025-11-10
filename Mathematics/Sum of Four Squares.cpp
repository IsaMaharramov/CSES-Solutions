#include "bits/stdc++.h" /// https://en.wikipedia.org/wiki/Lagrange%27s_four-square_theorem
using namespace std;
// #define int long long
constexpr int sz = 1e7 + 7;
constexpr int mod = 1e9 + 7;
 
struct em{
    int c, d;
};
 
vector<em> ts;
 
void pre_comp(){
  ts.assign(sz + 1, {-1, -1});
 
  int lim_i = static_cast<int>(sqrt(sz));
  for(int i = 0; i <= lim_i; ++i){
    long long i_sq = 1ll * i * i;
    int lim_j = static_cast<int>(sqrt(sz - i_sq));
    for(int j = 0; j <= lim_j; ++j){
      long long sm_sq = i_sq + 1ll * j * j;
      if(sm_sq > sz) break;
      if(ts[sm_sq].c == -1) ts[sm_sq] = em{i, j};
    }
  }
  return;
}
 
int n;
 
void solve(){
  cin >> n;
  int lim_a = static_cast<int>(sqrt(n));
  for(int a = 0; a <= lim_a; ++a){
    long long a_sq = 1ll * a * a;
    long long r1 = n - a_sq;
    int lim_b = static_cast<int>(sqrt(r1));
    for(int b = 0; b <= lim_b; ++b){
      long long b_sq = 1ll * b * b;
      long long r2 = r1 - b_sq;
 
      if(r2 >= 0 and r2 <= sz){
        const em &p = ts[r2];
        if(p.c != -1){
          int c = p.c;
          int d = p.d;
          cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
          return; 
        }
 
      }
    }
  }
  return;
}
 
signed main(){
  cout.tie(0)->sync_with_stdio(0);
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  cin >> t;
  pre_comp();
  while(t--) solve();
  return 0;
}