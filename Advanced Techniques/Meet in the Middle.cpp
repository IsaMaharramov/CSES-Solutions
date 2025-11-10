#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt,fma")
#define SPEED ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define oo 1000000001
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define ll long long
#define ull unsigned long long
 
using namespace std;
using ld = long double;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
inline void readInt(int &n){
    char ch;
    int sign = 1;
    while(ch = getchar(), isspace(ch)){//getchar()-->getchar_unlocked()
 
    };
    n = 0;
    if(ch == '-')
        sign = -1;
    else n = ch - '0';
    while(ch = getchar(), isdigit(ch))
        n = (n << 3) + (n << 1) + ch - '0';
    n *= sign;
}
 
int n, x, c;
 
vector<int> a;
 
unordered_map<ll, int> mp;
 
ll sm, ans;
int pw[23];
 
signed main(){
	SPEED;
	readInt(n); readInt(x);
	pw[0] = 1;
	for(register int i = 1; i < 22; ++i){
		pw[i] = (pw[i-1] << 1);
	}
	int mid = ((n + 1) >> 1);
	for(register int i = 1; i <= mid; ++i){
		readInt(c);
		if(i <= mid) a.eb(c);
	}
	int m = n - mid;
	vector<ll> sml;
	for(register int mask = 0; mask < pw[mid]; ++mask){
		sm = 0;
		for(register int i = 0; i < mid; ++i){
			if(mask & pw[i]){
				sm += a[i];
			}
		}
		sml.eb(sm);
		//mp[sm]++;
    }
    a.clear();
    for(register int i = mid + 1; i <= n; ++i){
    	readInt(c);
    	a.eb(c);
	}
	vector<ll> smr;
    for(register int mask = 0; mask < pw[m]; ++mask){
    	sm = 0;
    	for(register int i = 0; i < m; ++i){
    		if(mask & pw[i]){
    			sm += a[i];
			}
		}
		smr.eb(sm);
    	//ans += mp[x - sm];
	}
	sort(all(sml)), sort(all(smr));
	for(auto to : sml) ans += upper_bound(all(smr), x - to) - lower_bound(all(smr), x - to);
	
    cout << ans << '\n';
    return 0;
}