#include<iostream>
#include<vector>
#include<random>
#include<chrono>
#include<algorithm>
#include<map>
#define SPEED ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define oo 1000000001
#define rall(v) (v).rbegin(),(v).rend()
#define all(v) (v).begin(),(v).end()
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
 
int n, x;
int a[sz];
 
map<int, int> mp;
 
signed main(){
  SPEED;
  cin >> n >> x;
  int sm(0), ans(0);
  // sm = x + b
  // x = sm - b
  // -b = x - sm
  mp[0] = 1;
  for(register int i = 1; i <= n; ++i){
        cin >> a[i];
        sm += a[i];
        ans += mp[sm - x];
        mp[sm]++;
  }
  cout << ans << '\n';
  return 0;
}