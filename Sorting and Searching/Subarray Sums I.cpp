#include<iostream>
#include<vector>
#include<random>
#include<chrono>
#include<algorithm>
#define SPEED ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define oo 1000000001
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define ll long long
#define ull unsigned long long
 
using namespace std;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int sz = 2e5 + 5;
 
int n, x;
int a[sz];
 
signed main(){
	SPEED;
	cin >> n >> x;
	for(register int i = 1; i <= n; ++i){
        cin >> a[i];
	}
	int ans(0), l(0), sm(0);
	for(register int r = 1; r <= n; ++r){
        sm += a[r];
        while(sm > x){
            sm -= a[++l];
        }
        ans += (sm == x);
	}
	cout << ans << '\n';
	return 0;
}