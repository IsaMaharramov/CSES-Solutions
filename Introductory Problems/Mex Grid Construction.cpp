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
const int N=1e5+5;
 
int n;
int t[1 << 7][1 << 7];
 
signed main(){
    SPEED;
    cin >> n;
    memset(t, -1, sizeof(t));
    for(int i = 1; i <= n; ++i){
        t[i][1] = t[1][i] = i - 1;
    }  
    for(int i = 2; i <= n; ++i){
        for(int j = 2; j <= n; ++j){
            bitset<(1 << 10)> vis;
            int l = j - 1;
            while(l > 0) vis[t[i][l--]] = 1;
            l = i - 1;
            while(l > 0) vis[t[l--][j]] = 1;
            l = 0;
            while(vis[l]) ++l;
            t[i][j] = l;
        }
    }
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) cout << t[i][j] << "\n "[j != n];
}