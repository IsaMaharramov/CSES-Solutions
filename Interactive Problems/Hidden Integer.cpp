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
 
#define int long long
 
string s;
 
void solve(){
    int L(1), R{inf - 6}, mid, best{1};
    auto ask = [&](int y){
        cout << "? " << y << '\n';
        cout << flush;
        cin >> s;
        return (s == "NO");
    };
    while(L <= R){
        mid = L + ((R - L) >> 1);
        if(ask(mid)){
            best = mid;
            R = mid - 1;
        }else{
            L = mid + 1;
        }
    }
    cout << "! " << best << '\n';
    cout << flush;
}
 
signed main(){
    SPEED;
    solve();
    return 0;
}
