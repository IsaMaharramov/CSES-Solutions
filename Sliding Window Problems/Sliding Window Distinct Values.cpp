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
constexpr int sz = 2e5 + 5;
 
#define int long long
 
int k, n, x[sz], c[sz];
 
unordered_map<int, int> mp;
 
void solve(){
    cin >> n >> k;
    int cnt(0), ans(0);
    mp.clear();
    memset(c, 0, sizeof(c));
    for(int i = 1; i <= n; ++i){
        cin >> x[i];
        mp[x[i]];
    }
    for(auto &j : mp) j.S = ++cnt;
    for(int i = 1; i <= n; ++i){
        x[i] = mp[x[i]];
    }
    for(int i = 1; i <= n; ++i){
        if(c[x[i]] == 0) ++ans;
        c[x[i]]++;
        if(i - k >= 1){
            c[x[i - k]]--;
            if(!c[x[i - k]]) --ans;
        }
        if(i >= k){
            cout << ans << ' ';
        }
    }
 
 
 
}
 
signed main(){
    SPEED;
    solve();
    return 0;
}