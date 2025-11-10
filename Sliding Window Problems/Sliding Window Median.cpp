#include<iostream>
#include<vector>
#include<random>
#include<chrono>
#include<algorithm>
#include<map>
#include<set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define y1 y_1
 
using namespace std;
using ld = long double;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
using namespace __gnu_pbds;
#define ordered_set  tree<pii, null_type, less<pii>, rb_tree_tag,tree_order_statistics_node_update>
 
 
const int sz = 2e5 + 5;
 
int n, k, timel;
int a[sz];
 
ordered_set ost;
 
signed main(){
	SPEED;
	cin >> n >> k;
	for(register int i = 1; i <= n; ++i){
        cin >> a[i];
        ost.insert({a[i], ++timel});
        if(i > k){
            ost.erase(ost.lower_bound({a[i - k], 0}));
        }
        if(i >= k){
            cout << (*ost.find_by_order((k - 1) >> 1)).F << ' ';
        }
	}
	cout << '\n';
	return 0;
}