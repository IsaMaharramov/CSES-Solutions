#include<iostream>
#include<vector>
#include<random>
#include<chrono>
#include<algorithm>
#include<set>
#include<map>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
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
#define left lefttt
#define right righttt
#define y1 y_1
 
//using namespace __gnu_pbds;
//template<class T> using ost = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
using namespace std;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int sz = 2e5 + 5;
 
 
int n, m;
int arr[sz], idx[sz];
 
int mabs(int a){
	return (a > 0 ? a : -a);
}
 
signed main(){
	SPEED;
	cin >> n >> m;
	for(register int i = 1; i <= n; ++i){
		cin >> arr[i];
		idx[arr[i]] = i;
	}
	int ans{1};
	for(register int i = 1; i < n; ++i){
		ans += (idx[i] > idx[i+1]);
	}
	idx[n+1] = n + 1;
	for(register int i = 1, b, c, x, y; i <= m; ++i){
		cin >> x >> y;
		b = arr[x], c = arr[y];
		swap(arr[x], arr[y]);
 
		if(idx[b-1] <= idx[b] && idx[b-1] > y) ++ans;
		if(idx[b-1] > idx[b] && idx[b-1] <= y) --ans;
 
		if(idx[b] <= idx[b+1] && idx[b+1] < y) ++ans;
		if(idx[b] > idx[b+1] && idx[b+1] >= y) --ans;
 
		idx[b] = y;
 
		if(idx[c-1] <= idx[c] && idx[c-1] > x) ++ans;
		if(idx[c-1] > idx[c] && idx[c-1] <= x) --ans;
 
		if(idx[c] <= idx[c+1] && idx[c+1] < x) ++ans;
		if(idx[c+1] < idx[c] && idx[c+1] >= x) --ans;
 
        idx[c] = x;
 
		cout << ans << '\n';
	}
	return 0;
}