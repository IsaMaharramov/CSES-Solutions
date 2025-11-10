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
int t[1 << 10][1 << 10];
array<int, 8> dx = {-2, 2, 1, -1, -2, 1, 2, -1}, dy = {-1, 1, 2, -2, 1, -2, -1, 2};
 
signed main(){
    SPEED;
    cin >> n;
    memset(t, -1, sizeof(t));
    queue<pii> q;
    q.push({1, 1});
    t[1][1] = 0;
    while(!q.empty()){
        pii cur = q.front();
        q.pop();
        for(int i = 0; i < 8; ++i){
            pii to = pii{cur.F + dx[i], cur.S + dy[i]};
            if(max(to.F, to.S) > n or min(to.F, to.S) < 1) continue;
            if(t[to.F][to.S] != -1) continue;
            t[to.F][to.S] = t[cur.F][cur.S] + 1;
            q.push(to);
        }
    }
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) cout << t[i][j] << "\n "[j != n];
}