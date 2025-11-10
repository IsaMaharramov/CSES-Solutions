#include<bits/stdc++.h>
#define f first
#define s second
#define ull unsigned long long
#define int ull
using namespace std;
using pii = pair<int, int>;
using pll = pair<ull, ull>;
 
const int sz = 1e5 + 5;
const ull inf = 1e18 + 5;
 
int a, b, w, n, m, j;
 
vector<pii> g[2][sz];
array<vector<ull>, 2> d;
 
inline void Dijkstra(int bn){
	priority_queue<pll, vector<pll>, greater<pll>> q;
	d[j].assign(n+1, inf);
	d[j][bn] = 0;
	q.push({0, bn});
	while(!q.empty()){
		int cur = q.top().s, dist = q.top().f;
		q.pop();
		if(dist ^ d[j][cur]) continue;
		for(auto toto : g[1 ^ j][cur]){
			int to{toto.f}, w{toto.s};
			if(d[j][cur] + w < d[j][to]){
				d[j][to] = d[j][cur] + w;
				q.push({d[j][to], to});
			}
		}
	}
	return;
}
 
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(register int i = 1; i <= m; ++i){
		cin >> a >> b >> w;
		g[0][b].emplace_back((pii){a, w});
		g[1][a].emplace_back((pii){b, w});
	}
	Dijkstra(1);
	j = 1;
	Dijkstra(n);
	ull ans{inf};
	for(register int i = 1; i <= n; ++i){
		for(auto toto : g[1][i]){
			w = toto.s;
			w >>= 1;
			int to{toto.f};
			ans = min(ans, d[0][i] + d[1][to] + w);
		}
	}
	cout << ans << '\n';
	return 0;
}