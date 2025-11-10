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
 
int n, a, b;
 
void solve(){
    cin >> n >> a >> b;
    if((a + b) > n or (min(a, b) == 0) and (a + b)) return cout << "NO" << '\n', void(0);
    int tie = n - a - b;
 //   cout << tie<<endl;
    vector<int> A, B;
    for(int i = n - tie + 1; i <= n; ++i){
        A.eb(i), B.eb(i);
 
    }
    n -= tie;
  //  cout<<n<<endl;
    for(int i = 1; i <= n; ++i){
        A.eb(i);
    }
    for(int i = a + 1; i <= n; ++i){
        B.eb(i);
    }
    for(int i = 1; i <= a; ++i){
        B.eb(i);
    }
 
    cout << "YES" << '\n';
    n+=tie;
    for(int i = 0; i < n; ++i) cout << A[i] << " \n"[i == n - 1];
    for(int i = 0; i < n; ++i) cout << B[i] << " \n"[i == n - 1];    
}
 
signed main(){
    SPEED;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}