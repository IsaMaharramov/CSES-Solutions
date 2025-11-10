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
#define pb push_back
#define eb emplace_back
#define F first
#define S second
#define y0 jahdakdh
#define y1 jahsadakdakdh
using namespace std;
mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());
constexpr int sz = 1e5 + 5;
constexpr int inf = 1e9 + 7;
#define int long long
vector<int> mu, primes;
vector<bool> isPrime;
void mobiusSieve(){  // https://en.wikipedia.org/wiki/M%C3%B6bius_function
    int n = (int)mu.size() - 1;
    for(int i = 2; i <= n; ++i){
        if(isPrime[i]){
            primes.push_back(i);
            mu[i] = -1;
        }
        
        for(int &p : primes){
            if(i * p > n) break;
            
            isPrime[i * p] = false;
            
            if(i % p == 0){
                mu[i * p] = 0;
                break;
            }else{
                mu[i * p] = -mu[i];
            }
        }
    }
    
    return;
}
int n, x[sz];
void init(int mx){
    mu.resize(mx + 1), isPrime.resize(mx + 1);
    for(int i = 0; i <= mx; ++i) mu[i] = isPrime[i] = true;
    mobiusSieve();
}
unordered_map<int, int> cnt;
void solve(){
    cin >> n;
    int mx = 0;
    for(int i = 1; i <= n; ++i){
        cin >> x[i];
        cnt[x[i]]++;
        mx = max(mx, x[i]);
    }
    init(mx);
    int ans = 0, C = 0;
    for(int i = 1; i <= mx; ++i){
        if(!mu[i]) continue;
        C = 0;
        for(int j = i; j <= mx; j += i) C += cnt[j];
        ans += (C * (C - 1) / 2) * mu[i];
    }
    cout << ans << '\n';
} 
signed main(){
    SPEED;
    int T{1};
    //cin >> T;
    for(int t = 0; t < T; ++t) solve();
    return 0;
}