#include<bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
 
#define int long long
 
const int sz = 1e5 + 5;
const long long inf = 1e17 + 5000;
 
int n, m;
vector<pii> g[sz];
vector<long long> d(sz, inf);
 
inline void Dijkstra(int sn = 1){
	priority_queue<pll, vector<pll>, greater<pll>> q;
	q.push({0, sn});
	d[sn] = 0;
	while(!q.empty()){
		int cur = q.top().s, dist = q.top().f;
		q.pop();
		if(d[cur] ^ dist) continue;
		for(auto toto : g[cur]){
			int to = toto.f, w = toto.s;
			if(d[cur] + w < d[to]){
				d[to] = d[cur] + w;
				q.push({d[to], to});
			}
	    }
	}
	return;
}
 
 
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(register int i = 1, u, v, w; i <= m; ++i){
		cin >> u >> v >> w;
		g[u].emplace_back((pii){v, w});
	}
	Dijkstra();
	for(register int i = 1; i <= n; ++i) cout << d[i] << ' ';
	cout << '\n';
	return 0;
}