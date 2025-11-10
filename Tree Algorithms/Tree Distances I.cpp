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
 
int n;
 
 
set<int> g[sz];
 
int maxnode, maxd;
 
inline void dfs(int node, int fa,int dist){
	if(dist > maxd){
		maxnode = node;
		maxd = dist;
	}
	for(auto &to : g[node]){
		if(to ^ fa){
			dfs(to, node, dist + 1);
		}
	}
	return;
}
 
int d[2][sz];
 
inline void DFS(int node, int fa, bool pl){
	for(auto &to : g[node]){
		if(to ^ fa){
			d[pl][to] = d[pl][node] + 1;
			DFS(to, node, pl);
		}
	}
	return;
}
 
 
signed main(){
	SPEED;
	cin >> n;
	for(register int i = 1, a, b; i < n; ++i){
		cin >> a >> b;
		g[a].insert(b), g[b].insert(a);
	}
	dfs(1, 1, 0);
	dfs(maxnode, maxnode, maxd);
	int dia1 = maxnode;
	maxd = 0;
	dfs(dia1, dia1, 0);
	int dia2 = maxnode;
	DFS(dia1, dia1, false);
	DFS(dia2, dia2, true);
	for(register int i = 1; i <= n; ++i){
		cout << max(d[0][i], d[1][i]) << ' ';
	}
	return 0;
}