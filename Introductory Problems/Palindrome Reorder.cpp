#include<iostream>
#include<vector>
#include<random>
#include<chrono>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_set>
#define SPEED ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define oo 1000000001
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define ll long long
#define ull unsigned long long
 
using namespace std;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int sz = 2e5 + 5;
 
#define int ll
 
string s;
 
map<char, int> mp;
 
signed main(){
    SPEED;
    cin >> s;
    int n = (int)s.size();
    for(register int i = 0; i < n; ++i){
        mp[s[i]]++;
    }
    int k(0);
    for(auto &tot : mp){
        k += (tot.S & 1);
    }
    char it;
    string ans = "";
    if((!(n & 1) && k) || (k > 1)) return puts("NO SOLUTION"), 0;
    for(auto &tot : mp){
        if(tot.S & 1){
            it = tot.F;
        }
        for(register int i = 1; i <= (tot.S >> 1); ++i) ans += tot.F;
    }
    cout << ans;
    if(n & 1) cout << it;
    reverse(all(ans));
    cout << ans << '\n';
    return 0;
}