#include<iostream>
#include<vector>
#include<random>
#include<chrono>
#include<algorithm>
#include<set>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define SPEED ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define in(x) scanf("%d",&x)
#define IN(x) scanf("%I64d",&x)
#define oo 1000000001
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define ll long long
#define ull unsigned long long
#define left lefttt
#define right righttt
#define y1 y_1
 
//using namespace __gnu_pbds;
//template<class T> using ost = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
using namespace std;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int sz = 2e5 + 5;
const ull MAX = 1e18 - 5000;
 
#define int ull
 
int n, t;
int a[sz];
 
bool check(int& time){
	int res(0);
	for(register int i = 1; i <= n; ++i){
		res += time / a[i];
	}
	return res >= t;
}
 
signed main(){
    SPEED;
    cin >> n >> t;
    for(register int i = 1; i <= n; ++i){
    	cin >> a[i];
    }
    if(n == 1){
        cout << t * a[1] << '\n';
        return 0;
    }
    int l{1}, r{MAX}, mid, best;
    while(l <= r){
    	mid = l + ((r - l) >> 1);
    	if(check(mid)){
    		r = mid - 1;
    		best = mid;
    	}else{
    		l = mid + 1;
    	}
    }
    cout << best << '\n';
    return 0;
}