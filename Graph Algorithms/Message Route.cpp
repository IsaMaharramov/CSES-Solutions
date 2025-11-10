#include<iostream>
#include<vector>
#include<random>
#include<chrono>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_set>
#include<queue>
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
 
using namespace std;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int sz = 1e5 + 5;
 
int n, m;
 
unordered_set<int> g[sz];
 
bool vis[sz];
 
int fa[sz];
 
signed main(){
	SPEED;
	cin >> n >> m;
	for(register int i = 1, a, b; i <= m; ++i){
		cin >> a >> b;
		g[a].insert(b), g[b].insert(a);
	}
	for(register int i = 1; i <= n; ++i) fa[i] = i;
	queue<int> q;
	q.push(1), vis[1] = 1;
	vector<int> ans;
	while(!q.empty() && !vis[n]){
		int cur = q.front();
		q.pop();
		for(auto &to : g[cur]){
			if(vis[to]) continue;
			fa[to] = cur;
			q.push(to);
			vis[to] = true;
		}
	}
	if(!vis[n]) return puts("IMPOSSIBLE"), 0;
	int tot = n;
	while(tot ^ 1){
		ans.eb(tot);
		tot = fa[tot];
	}
	ans.eb(1);
	reverse(all(ans));
	cout << (int)ans.size() << '\n';
	for(auto &toto : ans)
		cout << toto << ' ';
	cout << '\n';
	return 0;
}