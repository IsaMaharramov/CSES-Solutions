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
 
#define int long long
 
int n;
 
bool p[N+100];
vector<int> ps;
 
inline void precomp(){
    fill(p, p + N, true);
    p[0] = p[1] = false;
    for(int i = 2; i <= N; ++i){
        if(p[i] and i * i <= N){
            for(int j = i * i; j <= N; j += i){
                p[j] = 0;
            }
        }
    }
    for(int i = 2; i <= N; ++i){
        if(p[i]) ps.eb(i);
    }
    return;
}
 
bool isprime(int x){
    if(x <= 1) return 0;
    if(x <= 3) return 1;
    if(x <= N) return p[x];
    for(auto &to : ps){
        if(to * to > x) break;
        if(x % to == 0) return 0;
    }
    return 1;
}
 
void solve(){
    cin >> n;
    ++n;
 
    for(int i = 0; i < 6; ++i){
        if(isprime(n)) return cout << n << '\n', void(0);
        ++n;
    }
 
    while(n % 6){
            if(isprime(n)) return cout << n << '\n', void(0);
            ++n;
    }
    if(isprime(n)) return cout << n << '\n', void(0);
 
    while(true){
        if(isprime(n - 1)) return cout << n - 1 << '\n', void(0);
        if(isprime(n + 1)) return cout << n + 1 << '\n', void(0);
        n += 6;
    }
    return;
}
 
signed main(){
    SPEED;
    precomp();
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}