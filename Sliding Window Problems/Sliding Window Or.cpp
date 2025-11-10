#pragma GCC optimize("O3,unroll-loops,inline")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include "bits/stdc++.h"
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

typedef long long ll;
// typedef long double ld;
// typedef unsigned long long ull;
// #define SPEED ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0)
// #define rall(v) (v).rbegin(),(v).rend()
// #define all(v) (v).begin(),(v).end()
// #define setp fixed<<setprecision
// #define OK cerr<<"OK"<<endl<<flush
// #define pii pair<int, int>
// #define pll pair<ll, ll>
// #define pb push_back
// #define eb emplace_back
// #define F first
// #define S second
// #define y0 jahdakdh
// #define y1 jahsadakdakdh
// #define endl '\n'
// const ll MOD=1e9+7;
// const ll mod=(1ll<<31)-1;
// const ld eps=1e-8;
// const ll MAXLONG=9223372036854775807;
// const ll MINLONG=-9223372036854775807;
using namespace std;
// mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());
const int N=1e7+1;
// constexpr int sz = 1e5 + 5;
// constexpr int inf = 1e9 + 7;
 
int a[N];
 
void solve(){
    int n, k; cin >> n >> k;
    cin >> a[0];
    array<ll, 3> mult;
    cin >> mult[0] >> mult[1] >> mult[2];
    for(int i = 1; i < n; ++i) a[i] = (mult[0] * a[i - 1] % mult[2] + mult[1]) % mult[2];
    int ans(0);
    for(int j = 0; j < 30; ++j){
        int mx = -1;
        for(int i = 0; i < n; ++i){
            if(a[i] & (1 << j)) mx = i + k -1;
            if(i >= k-1 && mx >= i) ans ^= 1<<j;
        }
    }
    cout << ans << '\n';
}
 
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    solve();
}