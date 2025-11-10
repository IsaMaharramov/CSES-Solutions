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
constexpr int inf = 1e9 + 7;
 
//#define int long long
 
int n, m, a[1 << 10], b[1 << 10], dp[1 << 10][1 << 10];
pii fa[1 << 10][1 << 10];
 
void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for(int i = 1; i <= m; ++i){
        cin >> b[i];
    }
 
 
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(a[i] == b[j]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
                fa[i][j] = pii{i - 1, j - 1};
            }else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if(dp[i - 1][j] > dp[i][j - 1]){
                    fa[i][j] = pii{i - 1, j};
                }else{
                    fa[i][j] = pii{i, j - 1};
                }
 
            }
        }   
    }
 
 
    cout << dp[n][m] << '\n';   
 
    stack<int> heap;
 
    pii cur = {n, m};
 
    while(cur.F and cur.S){
 
        if(a[cur.F] == b[cur.S]) heap.push(a[cur.F]); 
 
        cur = fa[cur.F][cur.S];
 
    }
 
 
    while(!heap.empty()){
        cout << heap.top() << ' ';
        heap.pop();
    }
    
 
 
}
 
signed main(){
    SPEED;
    solve();
    return 0;
}