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
int color[sz];
 
bool flag = true;
 
inline void dfs(int node){
    if(!flag) return;
    for(auto &to : g[node]){
        if(color[to]){
            if(color[to] ^ color[node]) continue;
            else{
                flag = false;
                return;
            }
        }else{
            color[to] = 3 - color[node];
            dfs(to);
        }
    }
    return;
}
 
signed main(){
	SPEED;
	cin >> n >> m;
	for(register int i = 1, a, b; i <= m; ++i){
        cin >> a >> b;
        g[a].insert(b), g[b].insert(a);
	}
	for(register int i = 1; i <= n && flag; ++i){
        if(!color[i]){
            color[i] = 1;
            dfs(i);
        }
	}
	if(!flag) return puts("IMPOSSIBLE"), 0;
	for(register int i = 1; i <= n; ++i)
        cout << color[i] << ' ';
    cout << '\n';
    return 0;
}