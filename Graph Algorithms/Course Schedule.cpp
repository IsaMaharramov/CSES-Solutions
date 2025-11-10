#include<iostream>
#include<vector>
#include<random>
#include<chrono>
#include<algorithm>
#include<set>
#include<map>
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
 
const int sz = 1e7 + 5;
 
int n, m;
 
int indegree[sz];
 
vector<int> g[sz];
 
vector<int> ans;
 
queue<int> q;
 
inline void Kahn_algorithm(){
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		ans.eb(cur);
		for(auto &to : g[cur]){
 			indegree[to]--;
			if(!indegree[to]){
				q.push(to);
			}
		}
	}
	return;
}
 
signed main(){
	SPEED;
	cin >> n >> m;
	for(register int i = 1, a, b; i <= m; ++i){
		cin >> a >> b;
		++indegree[b];
		g[a].eb(b);
	}
	for(register int i = 1; i <= n; ++i){
		if(!indegree[i]) q.push(i);
	}
	Kahn_algorithm();
	if((int)ans.size() != n) return puts("IMPOSSIBLE"), 0;
	for(auto &toto : ans)
		cout << toto << ' ';
	return 0;
}