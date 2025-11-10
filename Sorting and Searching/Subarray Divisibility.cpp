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
 
int n;
int a[sz];
 
map<int, int> mp;
 
signed main(){
	SPEED;
	cin >> n;
	int sm(0), ans(0);
	// a / n = k
	// (a - m) / n = k
	// a - m = n * k
	// a % n = m
	mp[0] = 1;
	for(register int i = 1; i <= n; ++i){
        cin >> a[i];
        if(a[i] < 0){
            a[i] += 1ll * (((-1) * a[i] / n) + 1) * n;
        }
        a[i] += n;
        sm += a[i];
        ans += mp[sm % n];
        mp[sm % n]++;
	}
	cout << ans << '\n';
	return 0;
}