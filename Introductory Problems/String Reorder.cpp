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
 
int n, m, cnt[27];
string s, ans = "";
 
 
 
bool isfeasible(char x){
    int mx = cnt[x - 'A'] - 1;
    for(int i = 0; i < 26; ++i){
        if(i == (x - 'A')) continue;
        mx = max(mx, cnt[i]);
    }
    if(m - mx < mx) return false;
    if(ans.back() == x) return false;
 
    return true;
}
 
 
//
 
signed main(){
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0)->sync_with_stdio(0);
    n = (cin >> s, (int)s.size());
 
    if(n == 1) return cout << s << '\n', 0;
 
 
 
    for(int i = 0; i < n; ++i) cnt[s[i] - 'A']++;
 
 
    auto cmp = [&](const char &a, const char &b){ return (a >= b); };
 
 
 
    priority_queue<char, vector<char>, decltype(cmp)> q(cmp), qn(cmp);
 
 
    m = n;
    
    for(int i = 0; i < 26; ++i) if(cnt[i]) q.push('A' + i);
 
 
    while(!q.empty()){ 
 
 
        while(!q.empty() and !isfeasible(q.top())){
            qn.push(q.top());
            q.pop();
        }
 
        if(q.empty()) return puts("-1"), 0;
 
        ans += q.top();
        --m;
        cnt[q.top() - 'A']--;
        if(!cnt[q.top() - 'A']) q.pop();
 
        while(!qn.empty()){
            q.push(qn.top());
            qn.pop();
        }
 
 
 
 
    }
 
    //if(m) return puts("-1"), 0;
 
    cout << ans << '\n';
 
 
}
