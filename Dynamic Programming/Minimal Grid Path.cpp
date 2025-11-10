#include "bits/stdc++.h"
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// #pragma GCC target ("avx,avx2,fma")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define SPEED ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0)
#define rall(v) (v).rbegin(),(v).rend()
#define all(v) (v).begin(),(v).end()
#define setp fixed<<setprecision
#define OK cerr<<"OK"<<endl<<flush
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define eb emplace_back
#define F first
#define S second
#define y0 jahdakdh
#define y1 jahsadakdakdh
#define endl '\n'
const ll MOD=1e9+7;
const ll mod=(1ll<<31)-1;
const ld eps=1e-8;
const ll MAXLONG=9223372036854775807;
const ll MINLONG=-9223372036854775807;
using namespace std;
mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());
const int N=1e6+6;
constexpr int sz = 1e5 + 5;
constexpr int inf = 1e9 + 7;
 
int n;
string s[1 << 12], ans = "";
 
void solve(){
   cin >> n;
   for(int i = 0; i < n; ++i){
        cin >> s[i];
   }
   vector<vector<bool>> vis(n, vector<bool> (n, false));
   queue<pii> q;
   vis[0][0] = (q.push({0, 0}), true);
   while(!q.empty()){
     int cnt = (int)q.size();
     queue<pii> qq(q);
     char mnc = 'Z';
     while(!qq.empty()){
          mnc = min(mnc, s[qq.front().F][qq.front().S]);
          qq.pop();
     }
     ans.pb(mnc);
     while(cnt--){
          pii cur = q.front();
          q.pop();
          if(s[cur.F][cur.S] != mnc) continue;
          if(cur.F + 1 < n and !vis[cur.F + 1][cur.S]) vis[cur.F + 1][cur.S] = (q.push({cur.F + 1, cur.S}), true);
          if(cur.S + 1 < n and !vis[cur.F][cur.S + 1]) vis[cur.F][cur.S + 1] = (q.push({cur.F, cur.S + 1}), true);
     }
   }
   cout << ans << '\n';
}
 
signed main(){
    SPEED;
    solve();
    return 0;
}